#include <iostream>
#include <string>

using namespace std;

class DongVat {
private:
    string TEN;
    int TUOI;
    float TrongLuong;
    float ChieuCao;

public:
    DongVat(string Ten, int Tuoi, float trong_luong, float chieu_cao);
    float Tinh_BMI();
    void SoSanh_Tuoi(DongVat other1, DongVat other2);
    void SoSanh_TrongLuong(DongVat other1, DongVat other2);
    string GetTen();
};

DongVat::DongVat(string Ten, int Tuoi, float trong_luong, float chieu_cao) {
    TEN = Ten;
    TUOI = Tuoi;
    TrongLuong = trong_luong;
    ChieuCao = chieu_cao;
}

float DongVat::Tinh_BMI() {
    float BMI = TrongLuong / (ChieuCao * ChieuCao);
    return BMI;
}

void DongVat::SoSanh_Tuoi(DongVat other1, DongVat other2) {
    if (other1.TUOI > other2.TUOI) {
        printf("%s lon tuoi hon %s \n", other1.TEN.c_str(), other2.TEN.c_str());
    } else if (other1.TUOI < other2.TUOI) {
        printf("%s nho tuoi hon %s \n", other1.TEN.c_str(), other2.TEN.c_str());
    } else {
        printf("%s bang tuoi %s \n", other1.TEN.c_str(), other2.TEN.c_str());
    }
}

void DongVat::SoSanh_TrongLuong(DongVat other1, DongVat other2) {
    if (other1.TrongLuong > other2.TrongLuong){
        printf("%s nang hon %s\n", other1.TEN.c_str(), other2.TEN.c_str());
    } else if (other1.TrongLuong < other2.TrongLuong){
        printf("%s nhe hon %s\n", other1.TEN.c_str(), other2.TEN.c_str());
    } else{
        printf("%s nang bang %s\n", other1.TEN.c_str(), other2.TEN.c_str());
    }
}

string DongVat::GetTen() {
    return TEN;
}

int main() {
    DongVat DV1("Meo", 4, 12, 22.7), DV2("Cho", 3, 23, 49.75);

    printf("BMI cua %s la: %.4f\n", DV1.GetTen().c_str(), DV1.Tinh_BMI());
    printf("BMI cua %s la: %.4f\n", DV2.GetTen().c_str(), DV2.Tinh_BMI());

    DV1.SoSanh_Tuoi(DV1, DV2);
    DV1.SoSanh_TrongLuong(DV1, DV2);

    return 0;
}
