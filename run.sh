#!/bin/bash

set -ex
gcc -o bin -O0 -I./task$1 task$1/*.c
./bin
