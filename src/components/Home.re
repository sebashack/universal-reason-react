let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("Welcome to my Blog")) </h1>
      <Link to_="/about"> (str("About")) </Link>
      <br />
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
