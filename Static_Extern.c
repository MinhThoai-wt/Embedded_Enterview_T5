#include <stdio.h>

extern int count;
extern void dem();

void text(){
    static int a=10; //Bien static cuc bo
    printf("a = %d\n",a);
    a++;
}
int main(int argc, char const *argv[])
{   
    text();
    text();
    text();

    printf("Count: %d\n", count);

    dem();
}