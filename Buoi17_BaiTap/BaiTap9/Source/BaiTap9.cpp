#include <stdio.h>
#include <string.h>

class XeHoi {
private:
    char mauSac[20];
    char kieuDongCo[20];
    float soKmDaDi;

public:
    XeHoi(const char* mau_sac, const char* kieu_dong_co, float so_km_da_di);
    float TinhChiPhiBaoTri();
    void KiemTraSoKmDaDi();
    void InThongTin();
};

XeHoi::XeHoi(const char* mau_sac, const char* kieu_dong_co, float so_km_da_di) {
    strncpy(mauSac, mau_sac, sizeof(mauSac));
    strncpy(kieuDongCo, kieu_dong_co, sizeof(kieuDongCo));
    soKmDaDi = so_km_da_di;
}

float XeHoi::TinhChiPhiBaoTri() {
    // Giả sử công thức tính chi phí bảo trì là 100.000 VND cho mỗi 1.000 km đã đi
    float chiPhi = (soKmDaDi / 1000) * 100000;
    return chiPhi;
}

void XeHoi::KiemTraSoKmDaDi() {
    printf("So km da di cua xe hoi: %.2f\n", soKmDaDi);
}

void XeHoi::InThongTin() {
    printf("Thong tin ve xe hoi:\n");
    printf("Mau sac: %s\n", mauSac);
    printf("Kieu dong co: %s\n", kieuDongCo);
    printf("So km da di: %.2f\n", soKmDaDi);
    printf("Chi phi bao tri: %.2f VND\n", TinhChiPhiBaoTri());
    printf("--------------------------------------------------\n");
}

int main() {
    XeHoi xe1("Do", "Dong co xang", 5000);
    xe1.KiemTraSoKmDaDi();
    xe1.InThongTin();

    XeHoi xe2("Xanh", "Dong co diesel", 10000);
    xe2.KiemTraSoKmDaDi();
    xe2.InThongTin();

    return 0;
}
