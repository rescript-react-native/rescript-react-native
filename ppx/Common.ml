open Ppxlib

let rec walk ~map ~push ~finalise ~acc records =
  match records with
  | [] -> finalise acc
  | elt :: rest ->
      let mapped = map elt in
      walk ~map ~push ~finalise ~acc:(push mapped acc) rest

let both f g a = (f a, g a)

let pushTuple (e1, e2) (l1, l2) = (e1 :: l1, e2 :: l2)

let cons a al = a :: al

let labelOfLident label =
  match label with
  | { txt = Lident txt; loc } -> { txt; loc }
  | { loc; _ } -> Location.raise_errorf ~loc "Unsupported token"
