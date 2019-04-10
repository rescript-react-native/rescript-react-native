#!/bin/bash

PKG=BsReactNative

OUTPUT=./dist/bs-react-native
LIB=../bs-react-native/lib/bs/src
PAGES=./legacy/pages
PUBLIC=./legacy/public
ODOC=$(which odoc)
if [[ $? != 0 ]] ; then
  echo "Missing odoc, please look at the CONTRIBUTING.md guide"
  exit 1
fi

# Ensure docs/dist exist
mkdir -p ${OUTPUT}

# Gather the sources to compile .odoc files
CMT_FILES=$(find ${LIB} -name "*.cmti")
MLD_FILES=$(find ${PAGES} -name "*.mld")

echo "Legacy doc: Compiling module docs..."
for file in ${CMT_FILES}; do
  ${ODOC} compile \
    -I ${LIB} \
    --pkg=${PKG} \
    --resolve-fwd-refs \
    ${file} \
  || exit 1
done

echo "Legacy doc: Compiling page docs..."
for file in ${MLD_FILES}; do
  odoc_file=$( echo $(basename ${file}) | sed "s/mld/odoc/")
  ${ODOC} compile \
    -I ${LIB} \
    --pkg=${PKG} \
    --resolve-fwd-refs \
    -o ${LIB}/${odoc_file} \
    ${file} \
  || exit 1
done

# Now we can look for the compiled .odoc files
ODOC_FILES=$(find ${LIB} -name "*.odoc")

echo "Legacy doc: Generating HTML..."
for file in ${ODOC_FILES}; do
  ${ODOC} html \
    -I ${LIB} \
    -o ${OUTPUT} \
    --syntax=re \
    --semantic-uris \
    ${file} \
  || exit 1
done

echo "Legacy doc: Adding static public files..."
cp -r ${PUBLIC}/* ${OUTPUT} || exit 1
