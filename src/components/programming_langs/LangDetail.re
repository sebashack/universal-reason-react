let str = ReasonReact.stringToElement;

let description =
  "It is peace and love however use it wisely or you will end up making a mess..."
  ++ "do not think that by using a tool you will overcome your mental habits and "
  ++ "misbehaviors. Anyways, no matter what you use... just try to be happy and "
  ++ "do exiting stuff!!!!!!";

module Language = {
  let component = ReasonReact.statelessComponent("Language");
  let make = (~title, ~description, _children) => {
    ...component,
    render: (_self) =>
      <div className="container">
        <h1 className="text-center"> (str(title)) </h1>
        <br />
        <div className="row">
          <div className="col-md-4" />
          <div className="col-md-4"> <h4 className="text-justify"> (str(description)) </h4> </div>
          <div className="col-md-4" />
        </div>
      </div>
  };
};

let component = ReasonReact.statelessComponent("LangDetail");

type params = {lang: string};

let make = (~params: params, _children) => {
  ...component,
  render: (_self) =>
    switch (String.lowercase(params.lang)) {
    | "haskell" => <Language title="Haskell" description />
    | "reason" => <Language title="Reason" description />
    | "scala" => <Language title="Scala" description />
    | _ => <Language title="Oop!" description />
    }
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => {
      let lang: string = jsProps##match_##params##lang;
      make(~params={lang: lang}, [||])
    }
  );
