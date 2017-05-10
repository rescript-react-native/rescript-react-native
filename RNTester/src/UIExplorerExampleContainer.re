let renderExample i ({title, description, render}: Example.t) =>
  <UIExplorerBlock key=(string_of_int i) title description> (render ()) </UIExplorerBlock>;

module UIExplorerExampleContainer = {
  include ReactRe.Component;
  let name = "UIExplorerExampleContainer";
  type props = {example: ExampleList.item};
  let render {props} =>
    <UIExplorerPage title=props.example.title>
      (ReactRe.listToElement (List.mapi renderExample props.example.examples))
    </UIExplorerPage>;
};

include ReactRe.CreateComponent UIExplorerExampleContainer;

let createElement ::example => wrapProps {example: example};