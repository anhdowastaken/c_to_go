#include "libgo.h"
#include "libc.h"
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

void Bar() {

}

long getMicrotime(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main()
{
    long i, start, end;
    long n = 10000000;

    start = getMicrotime();
    for (i = 0; i < n; i++)
    {
        Foo();
    }
    end = getMicrotime();
    printf("Call Foo() in Go so = %lu us\n", end - start);

    start = getMicrotime();
    for (i = 0; i < n; i++)
    {
        foo();
    }
    end = getMicrotime();
    printf("Call foo() in C so  = %lu us\n", end - start);


    start = getMicrotime();
    for (i = 0; i < n; i++)
    {
        Bar();
    }
    end = getMicrotime();
    printf("Call Bar() in C     = %lu us\n", end - start);

    return 0;
}