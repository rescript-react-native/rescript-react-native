open Node;
open Belt;

type t = {
  name: string,
  content: string,
};

let read = (globPattern: string) => {
  globPattern
  ->Glob.glob
  ->Future.mapOk(SortArray.String.stableSort)
  ->Future.mapOk(Array.reverse)
  ->Future.mapOk(files =>
      files->Array.map(item =>
        {name: item, content: Fs.readFileAsUtf8Sync(item)}
      )
    );
};

let write = files => {
  files->Array.forEach(file => {
    Mkdirp.sync(Path.dirname(file.name));
    Fs.writeFileAsUtf8Sync(file.name, file.content);
  });
};

let transform = (glob, transformer) =>
  glob
  ->read
  ->Future.map(files => files->Result.getExn)
  ->Future.map(transformer)
  ->Future.tap(write)
  ->Future.tap(files =>
      Js.log(files->Array.length->string_of_int ++ " files written")
    );
