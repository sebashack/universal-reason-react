[@bs.val] external setTimeout : (unit => Js.Promise.t(unit), int) => unit = "";

let str = ReasonReact.stringToElement;

let arr = ReasonReact.arrayToElement;

let fetch_repos = (url, callback) =>
  Fetch.fetch(url)
  |> Js.Promise.then_(Fetch.Response.json)
  |> Js.Promise.then_(
       (json) => {
         callback(DecodeRepo.decode_repos(json));
         Js.Promise.resolve()
       }
     );

module RepoDetail = {
  let component = ReasonReact.statelessComponent("RepoDetail");
  let make = (~repo: DecodeRepo.repo, _children) => {
    ...component,
    render: (_self) =>
      <tr>
        <td> (str(repo.name)) </td>
        <td> <a target="_blank" href=repo.url> (str(repo.url)) </a> </td>
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
  | LoadError
  | Clean;

let render_row = (repo: DecodeRepo.repo) => <RepoDetail key=(string_of_int(repo.id)) repo />;

let component = ReasonReact.reducerComponent("RepoIndex");

let make = (_children) => {
  let load_repos = (reduce) => {
    reduce((_) => Loading, [||]);
    setTimeout
      /* Simulate a heavy request with setTimeout */
      (
        () =>
          fetch_repos(
            "https://api.github.com/users/sebashack/repos",
            reduce((data) => Loaded(data))
          )
          |> Js.Promise.catch(
               (_) => {
                 reduce((_) => LoadError, [||]);
                 Js.Promise.resolve()
               }
             ),
        3000
      )
  };
  let clean_repos = (reduce) => reduce((_) => Clean, [||]);
  {
    ...component,
    initialState: () => {repos: [||], show: false, message: ""},
    reducer: (action, state) =>
      switch action {
      | Loading => ReasonReact.Update({...state, message: "Loading repositories... "})
      | Loaded(data) => ReasonReact.Update({...state, show: true, repos: data})
      | LoadError =>
        ReasonReact.Update({...state, message: "Sorry there was an error...", show: false})
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
                <thead>
                  <tr>
                    <th> (str("Name")) </th>
                    <th> (str("Url")) </th>
                    <th> (str("Language")) </th>
                  </tr>
                </thead>
                <tbody> (arr(Array.map(render_row, repos))) </tbody>
              </table>
              <br />
              <br />
              <br />
            </div>
          }
        )
      </div>
    }
  }
};

let default = ReasonReact.wrapReasonForJs(~component, (_jsProps) => make([||]));
