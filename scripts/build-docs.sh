#!/bin/bash

readonly PKG=BsReactNative

readonly DOCS=docs
readonly ODOC=$(which odoc)
readonly LIB=./lib/bs/src
readonly PAGES=./docs/pages

# Gather the sources to compile .odoc files
readonly CMT_FILES=$(find ${LIB} -name "*.cmti")
readonly MLD_FILES=$(find ${PAGES} -name "*.mld")

echo "<< Compiling module docs..."
for file in ${CMT_FILES}; do
  ${ODOC} compile \
    -I ${LIB} \
    --pkg=${PKG} \
    ${file}
done
echo ">> Done!"

echo "<< Compiling page docs..."
for file in ${MLD_FILES}; do
  odoc_file=$( echo $(basename ${file}) | sed "s/mld/odoc/")
  ${ODOC} compile \
    -I ${LIB} \
    --pkg=${PKG} \
    -o ${LIB}/${odoc_file} \
    ${file}
done
echo ">> Done!"

# Now we can look for the compiled .odoc files
readonly ODOC_FILES=$(find ${LIB} -name "*.odoc")

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
