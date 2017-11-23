let str = ReasonReact.stringToElement;

let arr = ReasonReact.arrayToElement;

let component = ReasonReact.statelessComponent("Layout");

let make = (children) => {
  ...component,
  render: (self) =>
    <div>
      <div>
        <nav className="navbar navbar-default">
          <div className="container">
            <div className="navbar-header">
              <a className="navbar-brand" href="#"> (str("Reason Life")) </a>
            </div>
          </div>
        </nav>
      </div>
      <div className="container"> (arr(children)) </div>
      <footer className="footer">
        <div className="container">
          <p className="text-muted"> (str("Reason-Life by Sebastian Pulido")) </p>
        </div>
      </footer>
    </div>
};

let default = (children) => ReasonReact.wrapReasonForJs(~component, (_jsProps) => make(children));
