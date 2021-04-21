#!/bin/bash

conanFile="$1"
location="$2"
locationConanFile="$location/$conanFile"

if ! test -e "$location"; then


  if ! mkdir -p "$location"; then

    echo "ERROR: $location was not created"
    exit 1
  fi
fi

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