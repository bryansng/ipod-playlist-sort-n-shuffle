#!/bin/sh
gcc -c main.c
gcc -c sortAndShuffle.c
gcc sortAndShuffle.o main.o -o main
./main
