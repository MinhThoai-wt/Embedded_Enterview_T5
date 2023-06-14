#include <stdio.h>
#include <stdint.h>
#include <string.h>

void TinhToan(char* array){
    int ChuaX=0, KhongX=0;
    int SoHangChuaX=0; //Số hạng có chứa x
    int SoHangKhongX=0; //So hang khong chua x
    char ToanTuTruoc='+';
    int n=strlen(array);
    float x;


    for(int i=0; i<n-1; i++){
        if((array[i]>='0')&&(array[i]<='9')){
            SoHangKhongX=SoHangKhongX*10 + (array[i]-'0');
            if(array[i+1]=='x'){
                SoHangChuaX=SoHangKhongX;
                SoHangKhongX=0;

            }
            continue;
        }
            
        if(array[i]=='+'||array[i]=='-'){
            if(array[i]=='+'){
                if(ToanTuTruoc=='+'){
                    ChuaX = ChuaX + SoHangChuaX;
                    KhongX = KhongX + SoHangKhongX;
                }
                if(ToanTuTruoc=='-'){
                    ChuaX = ChuaX - SoHangChuaX;
                    KhongX = KhongX - SoHangKhongX;
                }
                ToanTuTruoc=array[i];
                continue;
            }

            if(array[i]=='-'){
                if(ToanTuTruoc=='+'){
                    ChuaX = ChuaX + SoHangChuaX;
                    KhongX = KhongX + SoHangKhongX;
                }
                if(ToanTuTruoc=='-'){
                    ChuaX = ChuaX - SoHangChuaX;
                    KhongX = KhongX - SoHangKhongX;
                }
                ToanTuTruoc=array[i];
            }
            SoHangKhongX=0;
            SoHangChuaX=0;
        }
        if(i==n-2){
            KhongX = KhongX + SoHangKhongX;
        }
    }
    x=((float)KhongX)/ChuaX;
    printf("ChuaX: %f\n", x);
    

}

int main(){
    char array[]="22x - 6 - 6x + 31= 0";
    TinhToan(array);
    return 0;
}