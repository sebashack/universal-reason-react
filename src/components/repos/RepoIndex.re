let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("RepoIndex");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1> (str("My Repositories")) </h1>
      <p> (str("This is a list of all my github repos")) </p>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
