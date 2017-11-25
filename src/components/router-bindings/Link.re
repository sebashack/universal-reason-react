[@bs.module "../../../../../node_modules/react-router-dom/Link.js"]
external link : ReasonReact.reactClass =
  "default";

let make = (~to_: string, children) =>
  ReasonReact.wrapJsForReason(~reactClass=link, ~props={"to": to_}, children);
/* Another strategy would be to use the magic accessor ## with  */
/* [@bs.module] external routerLink : Js.t({..}) = "../../../../node_modules/react-router-dom/Link.js"; */
/* for example routerLink##default */
