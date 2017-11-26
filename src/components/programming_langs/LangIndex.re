let str = ReasonReact.stringToElement;

let arr = ReasonReact.arrayToElement;

module LangPreview = {
  let component = ReasonReact.statelessComponent("LangPreview");
  let make = (~path, ~lang, _children) => {
    ...component,
    render: (_self) =>
      <div className="col-md-4">
        <div className="img-thumbnail">
          <Link to_=(path ++ "/" ++ lang)>
            <img src=("/assets/" ++ lang ++ ".png") width="250" height="200" />
          </Link>
        </div>
      </div>
  };
};

/* Index Component */
type state = bool;

let component = ReasonReact.statelessComponent("LangsIndex");

let make = (~path: string, children_routes) => {
  ...component,
  render: (_self) =>
    <div>
      <h1 className="text-center">
        <strong> (str("My Favorite programming languages")) </strong>
      </h1>
      <br />
      <br />
      <div className="container">
        <div className="row">
          <LangPreview path lang="haskell" />
          <LangPreview path lang="scala" />
          <LangPreview path lang="reason" />
        </div>
      </div>
    </div>
};

let default = (path: string) =>
  ReasonReact.wrapReasonForJs(~component, (_jsProps) => make(~path, [||]));
