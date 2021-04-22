#!/bin/bash

buildDir="build"

if test -e "./$buildDir"; then

  if ! rm -rf "./$buildDir"; then

    echo "ERROR: Could not remove '$buildDir' directory"
    exit 1
  fi
fi

if ! mkdir "./$buildDir"; then

  echo "ERROR: Could not create '$buildDir' directory"
  exit 1
fi

cd "./$buildDir" &&
  cmake .. &&
  cmake --build . &&
  make install
