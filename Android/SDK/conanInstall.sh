#!/bin/bash

arch="$1"
variant="$2"

echo "Performing Conan install procedure for the arch. '$arch'"
echo "Build variant: $variant"

location=".cxx/cmake/$variant/$arch"
if ! test -e "$location"; then


  if ! mkdir -p "$location"; then

    echo "ERROR: $location was not created"
    exit 1
  fi
fi

conanFile="conanfile.txt"
locationConanFile="$location/$conanFile"

if test -e "$locationConanFile"; then

  if rm -f "$locationConanFile"; then

    echo "$locationConanFile: removed"
  else

    echo "ERROR: $locationConanFile was not removed"
    exit 1
  fi
fi

if cp "$conanFile" "$locationConanFile"; then


  echo "$conanFile copied to $locationConanFile"
else

  echo "ERROR: $conanFile was not copied to $locationConanFile"
  exit 1
fi

if cd "$location" &&
  conan install "./$conanFile" --profile "android_$arch" --build missing; then

  echo "Conan installation procedure completed"
else

  echo "ERROR: Conan installation procedure failed"
  exit 1
fi


