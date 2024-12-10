type target = [#_blank | #_self | #_parent | #_top]

// @todo find a zero cost way to support array of rel
// does passing an array of string to dom will automatically join with , when implicitely using toString on the array?
//
// list from https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/rel
// a / area column
type rel = [
  | #"external"
  | #alternate
  | #author
  | #bookmark
  | #help
  | #license
  | #next
  | #nofollow
  | #noopener
  | #noreferrer
  | #opener
  | #prev
  | #search
  | #tag
  | #ugc
]

type hrefAttrs = {
  download?: string,
  rel?: rel,
  target?: target,
}
