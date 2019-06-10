[@react.component]
let make = () =>
  <BsReactHelmet>
    <meta charSet="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <link
      rel="apple-touch-icon"
      sizes="180x180"
      href={Consts.baseUrl ++ "/apple-touch-icon.png"}
    />
    <link
      rel="icon"
      type_="image/png"
      sizes="32x32"
      href={Consts.baseUrl ++ "/favicon-32x32.png"}
    />
    <link
      rel="icon"
      type_="image/png"
      sizes="16x16"
      href={Consts.baseUrl ++ "/favicon-16x16.png"}
    />
    <link rel="manifest" href={Consts.baseUrl ++ "/site.webmanifest"} />
    {ReactDOMRe.createElementVariadic(
       "link",
       ~props=
         ReactDOMRe.objToDOMProps({
           "rel": "mask-icon",
           "href": {Consts.baseUrl ++ "/safari-pinned-tab.svg"},
           "color": "#222222",
         }),
       [||],
     )}
    <link rel="shortcut icon" href={Consts.baseUrl ++ "/favicon.ico"} />
    <meta name="msapplication-TileColor" content="#222222" />
    <meta
      name="msapplication-config"
      content={Consts.baseUrl ++ "/browserconfig.xml"}
    />
    <meta name="theme-color" content="#222222" />
    <link
      rel="stylesheet"
      href="//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/atom-one-light.min.css"
    />
    <meta
      name="viewport"
      content="width=device-width, initial-scale=1, viewport-fit=cover"
    />
    <style>
      {j|@-ms-viewport { width: device-width } @viewport { width: device-width }|j}
      ->React.string
    </style>
    <style>
      {j|
html {
  width: 100%;
  height: 100%;
  overflow-x:hidden;
  background: #fff;
  font-family: system-ui,-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,Ubuntu,"Helvetica Neue",sans-serif;
}
body {
  min-width: 100%;
  min-height: 100%;
  overflow-x: hidden;
}

@supports(padding: max(0px)) {
  body {
    /* https://webkit.org/blog/7929/designing-websites-for-iphone-x/ */
    padding-left: env(safe-area-inset-left);
    padding-right: env(safe-area-inset-right);
    /* padding-left: max(12px, env(safe-area-inset-left)); */
    /* padding-right: max(12px, env(safe-area-inset-right)); */
    padding-bottom: env(safe-area-inset-bottom);
  }
}

code {
  font-family: SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace;
}

h1, h2, h3, h4, h5, h6 {
  all: unset;
}

.hljs {
  font-size: 14px;
  line-height: 20px;
  padding: 20px;
  border: 1px solid rgba(0,0,0,0.05);
  background: rgba(0,0,0,0.01);
  border-radius: 4px;
}

.hljs code { background-color: transparent !important; }
.hljs.javascript { background-color: rgba(247, 223, 30, .03) }

.hljs-operator { color: #a626a4 }
.hljs-character { color: #50a14f }
.hljs-module-identifier { color: #4078f2 }
.hljs-constructor { color: #e45649 }

.stick { position: -webkit-sticky; position: sticky; }
|j}
      ->React.string
    </style>
  </BsReactHelmet>;
