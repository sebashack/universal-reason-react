[@bs.module "../../../../../node_modules/react-router-dom/Link.js"]
external link : ReasonReact.reactClass =
  "default";

let make = (~to_: string, ~className: option(string)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=link,
    ~props={"to": to_, "className": className},
    children
  );
/* Another strategy would be to use the magic accessor ## with  */
/* [@bs.module] external routerLink : Js.t({..}) = "../../../../node_modules/react-router-dom/Link.js"; */
/* for example routerLink##default */
