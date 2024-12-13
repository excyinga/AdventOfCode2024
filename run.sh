#!/bin/bash

set -ex
gcc -o bin -O0 task$1/*.c
./bin
