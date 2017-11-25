let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("Welcome to my Blog")) </h1>
      <br />
      <ul>
        <li> <Link to_="/about"> (str("About")) </Link> </li>
        <li> <Link to_="/contact"> (str("Contact")) </Link> </li>
        <li> <Link to_="/programming"> (str("Programming Languages")) </Link> </li>
      </ul>
      <br />
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
