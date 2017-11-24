let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("Welcome to my Blog")) </h1>
      <RouterLink to_="/about"> (str("About")) </RouterLink>
      <br />
      <a href="#"> (str("Page 2")) </a>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
