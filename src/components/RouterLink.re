[@bs.module "../../../../node_modules/react-router-dom/Link.js"] external routerLink : ReasonReact.reactClass = "Link";

let make = (~to_: string, children) =>
  ReasonReact.wrapJsForReason(~reactClass=routerLink, ~props={"to": to_}, children);



