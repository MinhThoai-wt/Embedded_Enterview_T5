#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const int e=20; //Luu o phan vung Text
char *arr="Hello"; //Luu o phan vung Text
/*-----------------------------------------------------------------------------------------*/
static int a = 15; //Luu o phan vung Data
int x =100; //Luu o phan vung Data
/*-----------------------------------------------------------------------------------------*/
static int z = 0; //Luu o phan vung Bss
int y = 0; //Luu o phan vung Bss
static int i; //Luu o phan vung Bss
static int j; //Luu o phan vung Bss


void test(){
    static int b=10; //Luu o phan vung Data
    static int h=0; //Luu o phan vung Bss
    a=a+30;
    printf("test: %d\n",a);
}

int tong(int m, int n)  //m, n duoc luu o phan vung Stack
{
    int k; //Phan vung Stack
    k=m+n;
    printf("k = %d\n",k);
    return k;
}

int main(int agrc, char const *argv[])
{
    test();
    a = a+25;
    printf("main: %d\n",a);

    tong(7,9);

/*-----------------------------------Phan vung Heap----------------------------------------*/
    uint8_t *arr1 = (uint8_t*)malloc(sizeof(uint8_t)*5); //Khoi tao mang arr
    for(int i=0;i<5;i++){
        arr1[i]=i;
        printf("i = %d\n",arr1[i]);
    }

    arr1=(uint8_t*)realloc(arr1, sizeof(uint8_t)*7); //Thay doi kich thuoc mang arr
    for(int i=0;i<7;i++){
        arr1[i]=2*i;
    }
    for(int i=0;i<7;i++){
        arr1[i]=i;
        printf("i = %d\n",arr1[i]);
    }

    free(arr1);
/*-----------------------------------------------------------------------------------------*/

    return 0;
}

