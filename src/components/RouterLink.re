[@bs.module] external routerLink : ReasonReact.reactClass = "./Link";

let make = (~_to: string, children) =>
  ReasonReact.wrapJsForReason(~reactClass=routerLink, ~props={"to": _to}, children);
