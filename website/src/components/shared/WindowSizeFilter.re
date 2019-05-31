open Belt;

let bpToS = Js.Float.toString;
let smallBreakpoint = 500.;

module Small = {
  let mq = "(min-width: " ++ smallBreakpoint->bpToS ++ "px)";
  let rawStyle = {j|
    @media $mq { .WindowSizeFilter-small { display: none } }
  |j};
  [@react.component]
  let make = (~style=?, ~children=?, ()) => {
    <>
      <BsReactHelmet> <style> rawStyle->React.string </style> </BsReactHelmet>
      <div className="WindowSizeFilter-small" ?style>
        {children->Option.getWithDefault(React.null)}
      </div>
    </>;
  };
};

module NotSmall = {
  let mq = "(max-width: " ++ (smallBreakpoint -. 1.)->bpToS ++ "px)";
  let rawStyle = {j|
    @media $mq { .WindowSizeFilter-notSmall { display: none } }
  |j};
  [@react.component]
  let make = (~style=?, ~children=?, ()) => {
    <>
      <BsReactHelmet> <style> rawStyle->React.string </style> </BsReactHelmet>
      <div className="WindowSizeFilter-notSmall" ?style>
        {children->Option.getWithDefault(React.null)}
      </div>
    </>;
  };
};
