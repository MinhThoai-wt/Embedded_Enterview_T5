#include <stdio.h>

class HinhTron{
    private:
        int BanKinh;
    public:
        void GetBanKinh(int R);
        float TinhChuVi();
        float TinhDienTich();
};

void HinhTron::GetBanKinh(int R){
    BanKinh = R;
}

float HinhTron::TinhChuVi(){
    return 2*3.14*BanKinh;
}

float HinhTron::TinhDienTich(){
    return 3.14*BanKinh*BanKinh;
}



int main(){
    HinhTron BanKinhR;
    BanKinhR.GetBanKinh(7);

    float ChuVi = BanKinhR.TinhChuVi();
    printf("Chu vi hinh tron: %.2f\n", ChuVi);

    float DienTich = BanKinhR.TinhDienTich();
    printf("Dien tich hinh tron: %.2f", DienTich);

    return 0;

}