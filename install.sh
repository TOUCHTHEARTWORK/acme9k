#!/bin/sh

if [ -z "$PLAN9" ]; then
  echo "PLAN9 not set;"
  echo "Please set it to the location of your plan9port installation."
  exit 1
fi

if [ $(whoami) != "root" ]; then
  mkdir -p ~/bin/9
  cp acme ~/bin/9/acme
  echo "acme has been installed to '${HOME}/bin/9/'"
else
  cp acme ${PLAN9}/bin/acme
  echo "acme has been installed to '${PLAN9}/bin/'"
fi