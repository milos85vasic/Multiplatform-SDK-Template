#!/bin/bash

arch="$1"
variant="$2"
conanFile="conanfile.txt"
location=".cxx/cmake/$variant/$arch"

echo "Performing Conan install procedure for the arch. '$arch'"
echo "Build variant: $variant"

if sh conanPrepare.sh "$conanFile" "$location"; then

  echo "Conan file prepared"
else

  echo "Conan file was not prepared"
  exit 1
fi

if cd "$location" &&
  conan install "./$conanFile" --profile "android_$arch" --build missing; then

  echo "Conan installation procedure completed for the arch. '$arch'"
else

  echo "ERROR: Conan installation procedure failed for the arch. '$arch'"
  exit 1
fi


