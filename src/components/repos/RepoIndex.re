[@bs.val] external setTimeout : (unit => unit, int) => unit = "";

let str = ReasonReact.stringToElement;

let arr = ReasonReact.arrayToElement;

let fetch_repos = (url, callback) =>
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.json)
    |> then_(
         (json) => {
           callback(DecodeRepo.decode_repos(json));
           resolve()
         }
       )
  );

module RepoDetail = {
  let component = ReasonReact.statelessComponent("RepoDetail");
  let make = (~repo: DecodeRepo.repo, _children) => {
    ...component,
    render: (_self) =>
      <tr>
        <td> (str(repo.name)) </td>
        <td> (str(repo.url)) </td>
        <td> (str(repo.language)) </td>
      </tr>
  };
};

type state = {
  repos: DecodeRepo.repos,
  show: bool,
  message: string
};

type action =
  | Loaded(DecodeRepo.repos)
  | Loading
  | Clean;

let render_table = (repo: DecodeRepo.repo) => <RepoDetail repo />;

let component = ReasonReact.reducerComponent("RepoIndex");

let make = (_children) => {
  let load_repos = (reduce) => {
    setTimeout(
      () =>
        fetch_repos("https://api.github.com/users/sebashack/repos", reduce((data) => Loaded(data)))
        |> ignore,
      3000
    );
    reduce((_) => Loading, [||])
  };
  let clean_repos = (reduce) => reduce((_) => Clean, [||]);
  {
    ...component,
    initialState: () => {repos: [||], show: false, message: ""},
    reducer: (action, state) =>
      switch action {
      | Loading => ReasonReact.Update({...state, message: "Loading repositories... "})
      | Loaded(data) => ReasonReact.Update({...state, show: true, repos: data})
      | Clean => ReasonReact.Update({show: false, message: "", repos: [||]})
      },
    render: ({state: {repos, show, message}, reduce}) => {
      let click_msg = show ? "Clean repos" : "Click to see my repos!";
      let click_reduce = show ? clean_repos : load_repos;
      <div>
        <h1> (str("My Repositories")) </h1>
        <br />
        <br />
        <button onClick=((_evt) => click_reduce(reduce))> (str(click_msg)) </button>
        <br />
        <br />
        <br />
        (
          if (! show) {
            <h3> (str(message)) </h3>
          } else {
            <div className="container">
              <h3> (str("This is a list of all my github repos: ")) </h3>
              <table className="table">
                <tr>
                  <th> (str("Name")) </th>
                  <th> (str("Url")) </th>
                  <th> (str("Language")) </th>
                </tr>
                <tbody> (arr(Array.map(render_table, repos))) </tbody>
              </table>
            </div>
          }
        )
      </div>
    }
  }
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
