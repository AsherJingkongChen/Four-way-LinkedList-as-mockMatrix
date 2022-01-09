#!/bin/bash
cd -- "$(dirname "$0")"
gcc -c test.c
gcc -c ./lib/Community.c
gcc -o test test.o Community.o
./test