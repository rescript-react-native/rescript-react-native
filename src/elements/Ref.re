type t('element);

type valueRef('element) = React.Ref.t(Js.nullable('element));
type callbackRef('element) = Js.nullable('element) => unit;

external value: valueRef('element) => t('element) = "%identity";

[@bs.module "react"]
external callback:
  (
    [@bs.uncurry] (Js.nullable('element) => unit),
    [@bs.as {json|[]|json}] _
  ) =>
  t('element) =
  "useCallback";
