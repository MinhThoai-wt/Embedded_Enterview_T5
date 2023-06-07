#include <stdio.h>
#include <stdint.h>

void shortList(uint8_t n, uint8_t array[])
{
    for(int i=0; i<n; i++){
        int h=0;
        int k=0;
        for(int j=0; j<n; j++){
            if(array[i]==array[j]){
                k=k+1;
                if(j<i){
                    h=1;
                }
            }
        }
        if(h==0){
            printf("So %d co %d phan tu \n", array[i], k);
        }
    }
}

int main()
{
    uint8_t array[]={2,2,7,8,6,2,8,16,22,15,7,9,10,11,9};
    uint8_t n=sizeof(array);
    shortList(n, array);
    return 0;
}