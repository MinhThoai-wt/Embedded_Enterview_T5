#include <stdio.h>
#include <stdint.h>

uint8_t Month[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char day[5];

void Thoi_gian(uint8_t Ngay, uint8_t Thang, uint16_t Nam){
    uint8_t Thu, day, d;
    uint64_t Tong_so_ngay=0;
    uint16_t Ngay_trong_nam=0;
    uint64_t a=0, b=0, c=0; // c: tổng số ngày, b: số ngày trong năm
    uint16_t n=0; //n là số năm nhuận tính từ năm hiện tại - 1
    uint16_t k=0; //k là số năm không nhuận tính từ năm hiện tại - 1
    uint64_t t=0;
    uint16_t r=0;

    for(int i=1; i<Nam; i++){
        if((i%4)==0){
            if((i%100)==0){
                if((Nam%400)==0){
                    n=n+1;
                }
            }
            else{
                Month[1]=28;
            }

            if((i%100)!=0){
                n=n+1;
            }
        }
    }
    k= Nam-n-1;
     
    /*--------------------------------------------------------------------------------------------------------------*/
    if((Nam%4)==0){ //Nếu năm chia hết cho 4 thì có 2 trường hợp:
        if(((Nam%100)==0)&&((Nam%400)==0)){ //Nếu năm hiện tại chia hết cho 100 và không chia hết cho 400 là năm nhuận
            if((Nam%400)==0){
                Month[1]=29;
            }
        }
        else{
            Month[1]=28;
        }

         if((Nam%100)!=0){ //Nếu năm hiện tại không chia hết cho 100
            Month[1]=29;
        }

    } //Nếu năm hiện tại chia hết cho 4 là năm không nhuận
    else{
        Month[1]=28;
    } 
    
    /*----------------------------------------------------------------------------------------------------------------*/
    if(Thang==1){
        b=Ngay;
    }
    else{
        b=0;
        int j=1;
        while(j<Thang){
            a=Month[j-1];
            b=b+a;
            j=j+1;
        }
        b=b+Ngay; //Số ngày tính từ đầu năm của năm hiện tại đến ngày tháng hiện tại của năm hiện tại
    }
    c = b + (n*366 + k*365); //Tổng số ngày từ ngày 1-1-1 đến ngày hiện tại

    
    /*-----------------------------------------------------------------------------------------------------------------*/
    Thu=c%7; // Số ngày lẻ của tuần

    if(Nam<2000){
        switch(Thu){
            case 4:
                printf("Thu hai");
                break;
            case 5:
                printf("Thu ba");
                break;
            case 6:
                printf("Thu tu");
                break;
            case 0:
                printf("Thu nam");
                break;
            case 1:
                printf("Thu sau");
                break;
            case 2:
                printf("Thu bay");
                break;
            case 3:
                printf("Chu nhat");
                break;
        }
    }

    if(Nam==2000){
        switch(Thu){
            case 3:
                printf("Thu ba");
                break;
            case 4:
                printf("Thu tu");
                break;
            case 5:
                printf("Thu nam");
                break;
            case 6:
                printf("Thu sau");
                break;
            case 0:
                printf("Thu bay");
                break;
            case 1:
                printf("Chu nhat");
                break;
            case 2:
                printf("Thu hai");
                break;
        }
    }

    if(Nam>2000){
        switch(Thu){
            case 3:
                printf("Thu hai");
                break;
            case 4:
                printf("Thu ba");
                break;
            case 5:
                printf("Thu tu");
                break;
            case 6:
                printf("Thu nam");
                break;
            case 0:
                printf("Thu sau");
                break;
            case 1:
                printf("Thu bay");
                break;
            case 2:
                printf("Chu nhat");
                break;
        }
    }
}

int main(){
    int Ngay =7;
    int Thang = 6;
    int Nam = 2023;  
    printf("Ngay %d - %d - %d\n: ",Ngay, Thang, Nam);
    Thoi_gian(Ngay, Thang, Nam);
    //printf("b: %d\n", b);

    return 0;
}
