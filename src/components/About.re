let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("About");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("About Me")) </h1>
      <p> (str("This is a small paragraph about my developer life...")) </p>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
