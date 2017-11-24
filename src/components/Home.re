let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("Welcome to my Blog")) </h1>
      <routerLink _to="/about"> (str("About")) </routerLink>
      <br />
      <a href="#"> (str("Page 2")) </a>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
