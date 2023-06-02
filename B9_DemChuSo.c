#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void shortList(uint8_t n, char array[])
{
    int k=0, h=0, z=0;
    int x=0, y=0;
    uint8_t array2[n];
    uint8_t array3[n];

    for(int i=0; i<n; i++){
        if(array[i]==' '){ //i=3,k=0
            if(array[i-1]==','){
                x=x+1;
                z=1;
            }
            /*Khai báo 2 mảng trung gian*/
            array2[y]=i - x; //Số lượng của mỗi chữ số của mỗi số trong mảng array;
            array3[y]=i - array2[y]-z; //Vị trí của mỗi số trong mảng array;

            x=i+1;
            y=y+1;
            z=0;
            /*---------------------------------------------------------------------*/
        } 
        /*Do số cuối trong trong array không có khoảng trống phía sau nó nên 
        dùng đoạn code này để tạo thêm số lượng cho số cuối*/
        if(i==(n-2)){ 
            array2[y]=n-x-1;
            array3[y]=n-array2[y]-1;

            y=y+1;
        }
        /*--------------------------------------------------------------------------*/
    }
    
    /*-----------------------So sánh các số với nhau-----------------------------------*/
    for(int i=0; i<y; i++){
        int r=0, g=0;
        for(int j=0; j<y; j++){
            int s=0;
            if(array2[i]==array2[j]){
                for(int t=0; t < array2[j]; t++){ //So sánh từng chữ số của số này với từng chữ số của số kia
                    if( array[array3[i]+t]==array[array3[j]+t]){
                        s=s+1;
                    }
                }

                if(s==array2[i]){ //Nếu tất cả các chữ số của số này bằng tất cả các chữ số của số kia thì 2 số bằng nhau
                    if(i>j){
                        g=1;
                    }
                    r=r+1;
                }
            }
        }
        
        /*Tránh lặp lại khi gặp cùng 1 số, nếu không dùng đoạn code này thì 1 số sẽ in nhiều 
        lần và kết quả sẽ khác nhau: Ví dụ: mot: co 2 so, mot: co 3 so, mot: co 5 so */
        if(g==0){
            for(int e=array3[i]; e<(array3[i]+array2[i]); e++){
                printf("%c",array[e]);
            }
            printf(": %d",r );
            printf(" \n");
        }
    }
}

int main()
{
    char array[]="mot hai mot hai mot mot, ba bon ba hai mot";
    uint8_t n=sizeof(array);
    shortList(n, array);
    return 0;
}
