open Ppxlib
open Common

let typedefs : structure ref = ref []

let finaliseLabelDeclaration ~loc ~name (records, variants) =
  Ast_builder.Default.(
    let rec getCovParams v =
      match v with
      | [] -> ([], [])
      | (vardecl, r) :: vs ->
          let cov, rest = getCovParams vs in
          ((ptyp_var ~loc vardecl, (Covariant, NoInjectivity)) :: cov, r :: rest)
    in
    let kind = Ptype_record records in
    let params, variants = getCovParams variants in
    let type_decl =
      type_declaration ~loc ~name ~cstrs:[] ~params ~private_:Public ~kind
        ~manifest:None
    in
    (pstr_type ~loc Recursive [ type_decl ], variants))

let genVariantType ~loc tags =
  Ast_builder.Default.ptyp_variant ~loc tags Open None

let mapType expr =
  match expr with
  | {
   pexp_desc =
     Pexp_extension
       ( { txt = "style"; _ },
         PStr
           [
             {
               pstr_desc =
                 Pstr_eval ({ pexp_desc = Pexp_record (records, None); _ }, _);
               _;
             };
           ] );
   pexp_loc = loc;
   _;
  } ->
      let variants =
        Style.(
          walk ~map:mapTag ~push:cons ~finalise:(genVariantType ~loc) ~acc:[]
            records)
      in
      let vardecl = gen_symbol ~prefix:"reactnative_stylesheet_variant_" () in
      Ast_builder.Default.
        ( [%type: [%t ptyp_var ~loc vardecl] ReactNative.Style.typed_t],
          Some (vardecl, variants) )
  | { pexp_loc = loc; _ } -> ([%type: ReactNative.Style.t], None)

let mapLabelDefinition ~loc (name, expr) =
  let pld_name = labelOfLident name in
  let pld_type, variant = mapType expr in
  ( {
      pld_name;
      pld_type;
      pld_loc = loc;
      pld_attributes = [];
      pld_mutable = Immutable;
    },
    variant )

let expand ~ctxt pat records =
  let push (e, opt) (el, rl) =
    match opt with Some r -> (e :: el, r :: rl) | None -> (e :: el, rl)
  in
  let loc = Expansion_context.Extension.extension_point_loc ctxt in
  let txt = gen_symbol ~prefix:"reactnative_stylesheet_" () in
  let name = { txt; loc } in
  let typedef, variants =
    walk ~map:(mapLabelDefinition ~loc) ~push
      ~finalise:(finaliseLabelDeclaration ~name ~loc)
      ~acc:([], []) records
  in
  let typename =
    Ast_builder.Default.ptyp_constr ~loc { txt = Lident txt; loc } variants
  in
  let records = Ast_builder.Default.pexp_record ~loc records None in

  let _ = typedefs := typedef :: !typedefs in

  [%stri
    let ([%p pat] : [%t typename]) = Utils.Sty.createStyleSheet [%e records]]

let extension =
  Extension.V3.declare "stylesheet" Extension.Context.Structure_item
    Ast_pattern.(
      pstr
        (pstr_value nonrecursive
           (value_binding ~pat:__ ~expr:(pexp_record __ none) ^:: nil)
        ^:: nil))
    expand

let rule = Context_free.Rule.extension extension

let impl structure = !typedefs @ structure
