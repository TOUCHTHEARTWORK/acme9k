#!/bin/sh

clang-format -i ./*.c
clang-format -i ./mail/*.c

mk

mv o.acme acme
