let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("Home")) </h1>
      <a href="#"> (ReasonReact.stringToElement("Page 1")) </a>
      <br />
      <a href="#"> (ReasonReact.stringToElement("Page 2")) </a>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
