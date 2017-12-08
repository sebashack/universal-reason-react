type repo = {
  url: string,
  language: string,
  name: string
};

type repos = list(repo);

let decode_repo = (json) : repo =>
  Json.Decode.{
    url: json |> field("url", string),
    language: json |> field("language", string),
    name: json |> field("name", string)
  };

let decode_repos = (json) : array(repo) => Json.Decode.(json |> array(decode_repo));
