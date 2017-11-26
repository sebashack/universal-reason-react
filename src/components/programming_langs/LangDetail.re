let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("LangDetail");

type params = {lang: string};

let make = (~params: params, _children) => {
  ...component,
  render: (_self) => <h1> (str(params.lang)) </h1>
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => {
      let lang: string = jsProps##match_##params##lang;
      make(~params={lang: lang}, [||])
    }
  );

module Haskell = {};

module Scala = {};

module Reason = {};
