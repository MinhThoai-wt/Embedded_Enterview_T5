#include <stdio.h>
#include <stdint.h>


void sortLish(uint8_t n, uint8_t array[]){
    for(uint8_t i=0; i<n-1; i++)
    {
        for(uint8_t j=0; j<n-1; j++)
        {
            if(array[j] > array[j+1]){ 
                uint8_t k = array[j];
                array[j]=array[j+1];
                array[j+1]=k;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
}

int main(int argc, char const *argv[]){
    uint8_t array[] = {2,4,1,8,3,6,1,5};
    uint8_t n=sizeof(array);
    sortLish(n, array);

    return 0;
}