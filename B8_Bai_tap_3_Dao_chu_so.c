#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void shortList(uint8_t n, char array[])
{
    char array2[n-1];
    uint8_t array3[n-1]; //Số lượng
    uint8_t array4[n-1]; //Vị trí
    uint8_t array5[n-1]; //Vị trí
    int x=0, y=0, z=0, s=0;
    
    /*Tạo mảng array2 để đảo ngược các phần tử của mảng array. Ví dụ array="mot hai ba bon"
    thì đảo ngược thành array2="nob ab iah tom*/
    for(int i=0; i<n-1; i++){
        array2[i]=array[(n-1)-i-1];

    }
    for(int i=0; i<n-1; i++){
        if(array2[i]==','){
            array2[i]=' ';
            array2[i-1]=',';
        }
    }

    for(int i=0; i<n; i++){
        if(array2[i]==' '){ //i=3,k=0
            if(array2[i-1]==','){
                x=x+1;
                z=1;
            }
            /*Khai báo 2 mảng trung gian*/
            array3[y]=i - x; //Số lượng của mỗi chữ số của mỗi số trong mảng array;
            array4[y]=i - array3[y]-z; //Vị trí của mỗi số trong mảng array;

            x=i+1;
            y=y+1;
            z=0;
            /*---------------------------------------------------------------------*/
        } 
        /*Do số cuối trong trong array không có khoảng trống phía sau nó nên 
        dùng đoạn code này để tạo thêm số lượng cho so cuoi*/
        if(i==(n-2)){ 
            array3[y]=n-x-1;
            array4[y]=n-array3[y]-1;

            y=y+1;
        }
        /*--------------------------------------------------------------------------*/
    }
    /*Đảo ngược vị trí của các chữ số của 1 số trong mảng array2. Ví dụ: array2="tom iah" 
    thì đảo thành array5="mot hai"*/
    for(int i=0; i<y; i++){ 
        int r=1;
        for(int j=array4[i]; j<(array4[i]+array3[i]); j++){ 
            array5[j]=array2[array4[i]+(array3[i])-r];
            r=r+1;
        }
        array5[(array4[i]+array3[i])]=' ';
    }
    /*In mang*/
    printf("\n");
    for(int i=0; i<n-1; i++){

        printf("%c", array5[i]);
    }
}
    

int main(int argc, char const *argv[]){
    char array[] ="mot hai ba bon nam, sau bay tam chin";
    uint8_t n=sizeof(array);
    shortList(n, array);

    return 0;
}
