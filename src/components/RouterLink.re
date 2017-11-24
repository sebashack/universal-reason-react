[@bs.module "../../../../node_modules/react-router-dom/Link.js"] external routerLink : ReasonReact.reactClass = "default";

let make = (~to_: string, children) =>
  ReasonReact.wrapJsForReason(~reactClass=routerLink, ~props={"to": to_}, children);


/* Another strategy would be to use the magic accessor ## with  */
/* [@bs.module] external routerLink : Js.t({..}) = "../../../../node_modules/react-router-dom/Link.js"; */
/* for example routerLink##deafault */



