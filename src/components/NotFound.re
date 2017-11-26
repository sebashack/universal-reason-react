let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("NotFound");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div> <h1> (str("Oppss...")) </h1> <p> (str("This page was not found... sorry")) </p> </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
