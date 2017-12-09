type repo = {
  id: int,
  url: string,
  language: string,
  name: string
};

type repos = array(repo);

let decode_repo = (json) : repo =>
  Json.Decode.{
    id: json |> field("id", int),
    url: json |> field("html_url", string),
    language: json |> field("language", string),
    name: json |> field("name", string)
  };

let decode_repos = (json) : array(repo) => Json.Decode.(json |> array(decode_repo));
