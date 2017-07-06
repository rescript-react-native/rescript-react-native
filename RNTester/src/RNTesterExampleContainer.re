let renderExample i ({title, description, render}: Example.t) =>
  <RNTesterBlock key=(string_of_int i) title description> (render ()) </RNTesterBlock>;

let component = ReasonReact.statelessComponent "RNTesterExampleContainer";

let make example::(example: ExampleList.item) _children => {
  ...component,
  render: fun _self =>
    <RNTesterPage title=example.title>
      (ReasonReact.arrayToElement (Array.mapi renderExample example.examples))
    </RNTesterPage>
};