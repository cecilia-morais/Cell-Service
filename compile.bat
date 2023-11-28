gcc -std=c99 -c modulos/*.c
gcc -std=c99 -c modulos/*.h
gcc -std=c99 -o a.exe main.c modulos/*.c