type item = {
  key: string,
  displayName: string,
  title: string,
  description: string,
  examples: list Example.t
};

module type ExampleT = {
  let displayName: string;
  let title: string;
  let description: string;
  let examples: list Example.t;
};

module MakeExample (Example: ExampleT) => {
  let item key => {
    key,
    displayName: Example.displayName,
    title: Example.title,
    description: Example.description,
    examples: Example.examples
  };
};

module Button = MakeExample ButtonExample;
module View = MakeExample ViewExample;

let components: array item = [|Button.item "ButtonExample", View.item "ViewExample" |];