#!/bin/sh
# https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/Arrays.html
# https://stackoverflow.com/questions/18548157/c-header-files-and-compilation-linking

gcc -c main.c
gcc -c sortAndShuffle.c
gcc sortAndShuffle.o main.o -o main
./main
