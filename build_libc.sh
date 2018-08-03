gcc -o libc.o -c libc.c
gcc -shared -o libc.so libc.o