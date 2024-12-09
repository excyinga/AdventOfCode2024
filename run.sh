#!/bin/bash

set -ex
gcc -o bin task$1/*.c
./bin
