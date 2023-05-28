#include <stdio.h>

void tong(int a, int b){
    printf("Tong cua %d va %d = %d\n",a,b,a+b);
}

void hieu(int a, int b){
    printf("Hieu cua %d va %d = %d\n",a,b,a-b);
}

void tich(int a, int b){
    printf("Tich cua %d va %d = %d\n",a,b,a*b);
}

void thuong(int a, int b){
    printf("Thuong cua %d va %d = %f\n",a,b,(float)(a/b));
}

void tinh_toan(int a, int b, void(*ptr)(int a, int b)) //Con tro ham tro thanh Input parameters
{  
    printf("Chuong trinh tinh toan\n");
    ptr(a,b);
}

int main(){

//Con tro ham:
    void (*ptr)(int a, int b)=&tong;
    //prt=&tong;
    ptr(8,9);
//Con tro ham tro thanh Input parameters
    tinh_toan(11,6,tich);

//Con tro dac biet (void):
    int i=5;
    double d=15.6;
    char c='B';

    void *ptr1=&i;
    printf("Gia tri cua i = %d\n",*(int*)ptr1);

    ptr1=&d;
    printf("Gia tri cua d = %f\n",*(double*)ptr1);

    ptr1=&c;
    printf("Gia tri cua d = %c\n",*(char*)ptr1);

//Point to Point:
    char *array="Hello";
    char array1[]="Hello";
    char *array2[]={"Hi", "Hello", "Word"};
    printf("test:%c\n",**(array2+2));

    int a=27;
    int *ptr2=&a;
    int **ptp=&ptr2;
    //int **ptp=&ptr2;

    printf("Gia tri cua *ptp = %d\n",**ptp);
    //printf("Gia tri cua **ptp = %d\n",**ptp);

}
