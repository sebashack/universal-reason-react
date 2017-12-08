let str = ReasonReact.stringToElement;

let arr = ReasonReact.arrayToElement;

/* "https://api.github.com/users/sebashack/repos" */
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

type state = DecodeRepo.repos;

type action =
  | Loaded(DecodeRepo.repos)
  | Loading;

let render_table = (repo: DecodeRepo.repo) => <RepoDetail repo />;

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
    initialState: () => [||],
    reducer: (action, _) =>
      switch action {
      | Loading => ReasonReact.Update([||])
      | Loaded(data) => ReasonReact.Update(data)
      },
    render: ({state: repos, reduce}) =>
      <div>
        <h1> (str("My Repositories")) </h1>
        <br />
        <button onClick=((_evt) => load_repos(reduce))> (str("Click to see my repos!")) </button>
        <br />
        <br />
        <br />
        (
          if (Array.length(repos) === 0) {
            <h3> (str("My repos are not loaded ...")) </h3>
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
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
