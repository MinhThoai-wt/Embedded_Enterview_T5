#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*----------------------------------Struct------------------------------------*/
struct DataA
{
    uint16_t arr1[7];
    uint8_t arr2[9];
    uint32_t arr3[15];
};
/*----------------------------------------------------------------------------*/

/*----------------------------------Union-------------------------------------*/
typedef union
{
    uint32_t a;
    uint8_t b;
    uint64_t c;
    
    char test1[6]; //5 byte
    char test2[3];
    /* data */
}TypeData;

void Hien_thi_Data(TypeData data){
    printf("a: %lu, b: %lu, c:%lu\n",data.a, data.b, data.c);
}
/*---------------------------------------------------------------------------*/

int main(int argc, char const *argv[])
{
/*----------------------------------Struct------------------------------------*/
    printf("Size: %lu\n",sizeof(struct DataA));
/*----------------------------------------------------------------------------*/

/*----------------------------------Union-------------------------------------*/   
    TypeData data;

    printf("Dia chi cua Union: %d\n", &data);
    printf("Dia chi cua a: %d\n", &(data.a));
    printf("Dia chi cua b: %d\n", &(data.b));
    printf("Dia chi cua c: %d\n", &(data.c));

    data.a=19;
    data.b=81;
    data.c=52;

    Hien_thi_Data(data);
    /*------------------------------------------------*/

    strcpy(data.test1, (char*)"Hello");
    data.test1[5] = '\0';

    strcpy(data.test2, (char*)"Hi");
    data.test2[2] = '\0';

    printf("test: %s\n",data.test1);
/*---------------------------------------------------------------------------*/

    return 0;
}
