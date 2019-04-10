let pct = num => num |> Printf.sprintf("%.2f%%");
module Size = {
  type t = string;
  external pt: float => t = "%identity";
  let pct: float => t = pct->Obj.magic;
};
