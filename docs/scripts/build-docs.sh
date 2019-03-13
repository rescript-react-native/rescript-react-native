#!/bin/bash

PKG=BsReactNative

DOCS=docs/dist
LIB=./lib/bs/src
PAGES=./docs/pages
PUBLIC=./docs/public/
ODOC=$(which odoc)
if [[ $? != 0 ]] ; then
  echo "Missing odoc, please look at the CONTRIBUTING.md guide"
  exit 1
fi

# Ensure docs/dist exist
mkdir -p ${DOCS}

# Gather the sources to compile .odoc files
CMT_FILES=$(find ${LIB} -name "*.cmti")
MLD_FILES=$(find ${PAGES} -name "*.mld")

echo "<< Compiling module docs..."
for file in ${CMT_FILES}; do
  ${ODOC} compile \
    -I ${LIB} \
    --pkg=${PKG} \
    --resolve-fwd-refs \
    ${file}
done
echo ">> Done!"

echo "<< Compiling page docs..."
for file in ${MLD_FILES}; do
  odoc_file=$( echo $(basename ${file}) | sed "s/mld/odoc/")
  ${ODOC} compile \
    -I ${LIB} \
    --pkg=${PKG} \
    --resolve-fwd-refs \
    -o ${LIB}/${odoc_file} \
    ${file}
done
echo ">> Done!"

# Now we can look for the compiled .odoc files
ODOC_FILES=$(find ${LIB} -name "*.odoc")

echo "<< Generating HTML..."
for file in ${ODOC_FILES}; do
  ${ODOC} html \
    -I ${LIB} \
    -o ${DOCS} \
    --syntax=re \
    --semantic-uris \
    ${file}
done
echo ">> Done!"

echo "<< Adding static public files..."
cp -r ${PUBLIC} ${DOCS}
echo ">> Done!"

echo "<< Editing html files to inject meta..."
META="<link rel=\"apple-touch-icon\" sizes=\"180x180\" href=\"/apple-touch-icon.png\">
<link rel=\"icon\" type=\"image/png\" sizes=\"32x32\" href=\"/favicon-32x32.png\">
<link rel=\"icon\" type=\"image/png\" sizes=\"16x16\" href=\"/favicon-16x16.png\">
<link rel=\"manifest\" href=\"/site.webmanifest\">
<link rel=\"mask-icon\" href=\"/safari-pinned-tab.svg\" color=\"#222222\">
<meta name=\"msapplication-TileColor\" content=\"#222222\">
<meta name=\"theme-color\" content=\"#ffffff\">"
yarn replace "<html xmlns=\"http://www.w3.org/1999/xhtml\"><head><title>" "<html xmlns=\"http://www.w3.org/1999/xhtml\"><head>$META<title>" ${DOCS} --recursive --include="*.html"
echo ">> Done!"
