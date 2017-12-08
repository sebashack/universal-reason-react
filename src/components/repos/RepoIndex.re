let str = ReasonReact.stringToElement;

/* "https://api.github.com/users/sebashack/repos" */
let fetch_repos = (url, callback) =>
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.json)
    |> then_(
         (json) => {
           callback("Your wonderful repos!!!!");
           Js.log(DecodeRepo.decode_repos(json));
           resolve()
         }
       )
  );

/* then_(Fetch.Response.json).then_((text) => Js.log(text)).resolve; */
type state = string;

type action =
  | Loaded(string)
  | Loading;

let component = ReasonReact.reducerComponent("RepoIndex");

let make = (_children) => {
  let load_repos = (reduce) => {
    fetch_repos("https://api.github.com/users/sebashack/repos", reduce((data) => Loaded(data)))
    |> ignore;
    reduce((_) => Loading);
    ()
  };
  {
    ...component,
    initialState: () => "",
    reducer: (action, _) =>
      switch action {
      | Loading => ReasonReact.Update("")
      | Loaded(data) => ReasonReact.Update(data)
      },
    render: ({state: text, reduce}) =>
      <div>
        <h1> (str("My Repositories")) </h1>
        <br />
        <button onClick=((_evt) => load_repos(reduce))> (str("Click to see my repos!")) </button>
        <br />
        <br />
        (
          if (text === "") {
            <p> (str("My repos are not loaded")) </p>
          } else {
            <p> (str("This is a list of all my github repos: " ++ text)) </p>
          }
        )
      </div>
  }
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
