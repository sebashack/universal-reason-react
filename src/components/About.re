[@bs.val] external setTimeout : (unit => Js.Promise.t(unit), int) => unit = "";

let str = ReasonReact.stringToElement;

let decode_bio = (json) : string => json |> Json.Decode.field("bio", Json.Decode.string);

let fetch_bio = (url, callback) =>
  Fetch.fetch(url)
  |> Js.Promise.then_(Fetch.Response.json)
  |> Js.Promise.then_(
       (json) => {
         callback(decode_bio(json));
         Js.Promise.resolve()
       }
     );

type action =
  | Loaded(string)
  | LoadError;

type state = string;

let component = ReasonReact.reducerComponent("About");

let make = (_children) => {
  let load_bio = (reduce) =>
    setTimeout
      /* Simulate a heavy request with setTimeout */
      (
        () =>
          fetch_bio("https://api.github.com/users/sebashack", reduce((data) => Loaded(data)))
          |> Js.Promise.catch(
               (_) => {
                 reduce((_) => LoadError, "Sorry there was an error ... ");
                 Js.Promise.resolve()
               }
             ),
        500
      );
  {
    ...component,
    didMount: (_self) => ReasonReact.SideEffects((self) => load_bio(self.reduce)),
    initialState: () => "Loading biography ...",
    reducer: (action, _state) =>
      switch action {
      | Loaded(bio) => ReasonReact.Update(bio)
      | LoadError => ReasonReact.Update("Sorry there was an error...")
      },
    render: (self) => <div> <br /> <h1> (str("About Me")) </h1> <p> (str(self.state)) </p> </div>
  }
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
