let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Contact");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("Contact Me")) </h1>
      <p> (str("You can find me on GitHub as sebashack")) </p>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
