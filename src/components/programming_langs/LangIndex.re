let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("LangsIndex");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <div>
      <h1 className="text-center"> (str("My favorite programming languages")) </h1>
      <br />
      <div className="container">
        <div className="row">
          <div className="col-md-4"> <h2 className="text-center"> (str("Haskell")) </h2> </div>
          <div className="col-md-4"> <h2 className="text-center"> (str("Scala")) </h2> </div>
          <div className="col-md-4"> <h2 className="text-center"> (str("Reason")) </h2> </div>
        </div>
      </div>
    </div>
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
