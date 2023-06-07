#include <stdio.h>
#include "test.c"

#define MAX 10
#define Tong(a,b) a+b


int main(int agrc, char const *argv[]){
    int a=7, b=16;
    printf("Hello\n");
    HienThi();
    printf("MAX = %d\n",MAX);
    printf("Tong %d va %d la: %d\n", a, b, Tong(a,b));

    return 0;
}