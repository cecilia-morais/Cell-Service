gcc -std=c99 -g -c modulos/*.c
gcc -std=c99 -g -c modulos/*.h
gcc -std=c99 -g -o a.exe main.c modulos/*.c