#!/bin/sh

if [ ! -e ./config.h ]; then
  cp config.def.h config.h
fi

clang-format -i ./*.c
clang-format -i ./mail/*.c
clang-format -i ./libframe/*.c

mk clean
mk

mv o.acme acme
