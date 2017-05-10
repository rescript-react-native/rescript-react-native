let renderExample i ({title, description, render}: Example.t) =>
  <RNTesterBlock key=(string_of_int i) title description> (render ()) </RNTesterBlock>;

module RNTesterExampleContainer = {
  include ReactRe.Component;
  let name = "RNTesterExampleContainer";
  type props = {example: ExampleList.item};
  let render {props} =>
    <RNTesterPage title=props.example.title>
      (ReactRe.listToElement (List.mapi renderExample props.example.examples))
    </RNTesterPage>;
};

include ReactRe.CreateComponent RNTesterExampleContainer;

let createElement ::example => wrapProps {example: example};