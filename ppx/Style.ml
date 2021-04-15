open Ppxlib
open Common

let unescape escaped =
  match escaped with
  | "flexStart" -> Some "flex-start"
  | "flexEnd" -> Some "flex-end"
  | "spaceBetween" -> Some "space-between"
  | "spaceAround" -> Some "space-around"
  | "_end" -> Some "end"
  | "rowReverse" -> Some "row-reverse"
  | "columnReverse" -> Some "column-reverse"
  | "spaceEvenly" -> Some "space-evenly"
  | "inherit_" -> Some "inherit"
  | "_100" -> Some "100"
  | "_200" -> Some "200"
  | "_300" -> Some "300"
  | "_400" -> Some "400"
  | "_500" -> Some "500"
  | "_600" -> Some "600"
  | "_700" -> Some "700"
  | "_800" -> Some "800"
  | "_900" -> Some "900"
  | "lineThrough" -> Some "line-through"
  | "underlineLineThrough" -> Some "underline line-through"
  | _ -> None

let buildType ~loc tags =
  Ast_builder.Default.(
    [%type: [%t ptyp_variant ~loc tags Open None] ReactNative.Style.typed_t])

let finalizeStyle ~loc (tags, records) =
  Ast_builder.Default.(
    let txt = gen_symbol ~prefix:"style_gen_" () in
    let pat = ppat_var ~loc { txt; loc } in
    let ident = pexp_ident ~loc { txt = lident txt; loc } in
    let apply = pexp_apply ~loc [%expr ReactNative.Style.style] records in
    [%expr
      let ([%p pat] : [%t buildType ~loc tags]) = Obj.magic [%e apply] in
      [%e ident]])

let mapTag (lident, _) =
  let label = labelOfLident lident in
  let { loc } = label in
  { prf_desc = Rtag (label, false, []); prf_loc = loc; prf_attributes = [] }

let mapArg (lident, expr) =
  let { txt; _ } = labelOfLident lident in
  (Labelled txt, expr)

let expand ~ctxt =
  let loc = Expansion_context.Extension.extension_point_loc ctxt in
  walk ~map:(both mapTag mapArg) ~finalise:(finalizeStyle ~loc) ~push:pushTuple
    ~acc:([], [ (Nolabel, [%expr ()]) ])

let extension =
  Extension.V3.declare "style" Extension.Context.Expression
    Ast_pattern.(single_expr_payload (pexp_record __ none))
    expand

let rule = Context_free.Rule.extension extension
