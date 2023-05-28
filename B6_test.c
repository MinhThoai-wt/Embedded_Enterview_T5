#include <stdio.h>

static int count=16; //Bien static toan cuc

void dem(){
    printf("count: %d", count);
    count++;
}
