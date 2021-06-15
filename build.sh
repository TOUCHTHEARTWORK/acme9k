#!/bin/sh

clang-format -i ./*.c
clang-format -i ./mail/*.c

mk clean
mk

mv o.acme acme
