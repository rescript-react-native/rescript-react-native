#!/bin/bash

PKG=BsReactNative

DOCS=docs
ODOC=$(which odoc)
LIB=./lib/bs/src
PAGES=./docs/pages

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
