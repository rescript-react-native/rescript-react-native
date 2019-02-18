let renderExample = (i, {title, description, render}: Example.t) =>
  <RNTesterBlock key={string_of_int(i)} title description>
    {render()}
  </RNTesterBlock>;

let component = ReasonReact.statelessComponent("RNTesterExampleContainer");

let make = (~example: ExampleList.item, _children) => {
  ...component,
  render: _self =>
    <RNTesterPage title={example.title}>
      {ReasonReact.array(Array.mapi(renderExample, example.examples))}
    </RNTesterPage>,
};
