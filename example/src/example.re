type t = {
  title: string,
  description: option(string),
  render: unit => ReasonReact.reactElement,
};
