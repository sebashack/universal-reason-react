let str = ReasonReact.stringToElement;

let arr = ReasonReact.arrayToElement;

let component = ReasonReact.statelessComponent("Layout");

let make = (children) => {
  ...component,
  render: (_self) =>
    <div>
      <div>
        <nav className="navbar navbar-default">
          <div className="container">
            <div className="navbar-header">
              <Link to_="/" className="navbar-brand"> (str("Reason Life")) </Link>
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
