#!/bin/bash

if ! ../Implementation/buildAndInstall.sh; then

  echo "ERROR: Could not build and install the library"
  exit 1
fi

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

cd "./$buildDir" && cmake .. && make -j "$(getconf _NPROCESSORS_ONLN)" && ctest