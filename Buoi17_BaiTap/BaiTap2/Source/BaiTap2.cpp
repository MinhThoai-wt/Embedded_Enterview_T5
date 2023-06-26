#include <iostream>
#include <cmath>
class HinhChuNhat{
    private:
        int ChieuDai;
        int ChieuRong;
        int Chu_Vi;
        int Dien_Tich;
        float Duong_Cheo;
    public:
        void LayKichThuoc(int chieu_dai, int chieu_rong);
        void ChuVi();
        void DienTich();
        void DuongCheo();
};

void HinhChuNhat::LayKichThuoc(int chieu_dai, int chieu_rong){
    ChieuDai = chieu_dai;
    ChieuRong = chieu_rong;
};

void HinhChuNhat::ChuVi(){
    Chu_Vi = (ChieuDai+ChieuRong)*2;
    printf("ChuVi = %d\n", Chu_Vi);
};

void HinhChuNhat::DienTich(){
    Dien_Tich = ChieuDai*ChieuRong;
    printf("ChuVi = %d\n", Dien_Tich);
};

void HinhChuNhat::DuongCheo(){
    Duong_Cheo = sqrt(pow(ChieuDai, 2)+ pow(ChieuRong, 2));
    printf("Duong cheo = %f\n", Duong_Cheo);
};

int main(){
    HinhChuNhat hcn;
    hcn.LayKichThuoc(7, 25);
    hcn.ChuVi();
    hcn.DienTich();
    hcn.DuongCheo();
    return 0;
}