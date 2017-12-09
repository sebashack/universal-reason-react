type repo = {
  id: int,
  url: string,
  language: string,
  name: string
};

type repos = array(repo);

let decode_repo = (json) : repo => {
  id: json |> Json.Decode.field("id", Json.Decode.int),
  url: json |> Json.Decode.field("html_url", Json.Decode.string),
  language: json |> Json.Decode.field("language", Json.Decode.string),
  name: json |> Json.Decode.field("name", Json.Decode.string)
};

let decode_repos = (json) : array(repo) => Json.Decode.(json |> array(decode_repo));
