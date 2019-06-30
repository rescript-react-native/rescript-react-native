open ReactNative;

let handleClick = _event => Js.log("clicked!");

[@react.component]
let make = (~message) => {
  React.useEffect(() => {
    Js.log("Hey!");
    None;
  });
  <Button onPress=handleClick title=message />;
};
