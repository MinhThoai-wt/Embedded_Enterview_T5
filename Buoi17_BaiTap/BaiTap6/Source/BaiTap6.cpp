#include <iostream>
#include <string>

class PhanSo{
    private:
        int TuSo;
        int MauSo;
        float Number;
    public:
        PhanSo(int tu_so, int mau_so);
        float PhepToan_Cong(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4);
        float PhepToan_Tru(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4);
        float PhepToan_Nhan(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4);
        float PhepToan_Chia(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4);
};


PhanSo::PhanSo(int tu_so, int mau_so){
    TuSo = tu_so;
    MauSo = mau_so;
    Number = float(tu_so)/mau_so;
}
float PhanSo::PhepToan_Cong(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4){
    float Cong = ps1.Number + ps2.Number + ps3.Number + ps4.Number;
    return Cong;
}

float PhanSo::PhepToan_Tru(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4){
    float Tru = ps1.Number - ps2.Number - ps3.Number - ps4.Number;
    return Tru;
}

float PhanSo::PhepToan_Nhan(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4){
    float Nhan = ps1.Number*ps2.Number*ps3.Number*ps4.Number;
    return Nhan;
}

float PhanSo::PhepToan_Chia(PhanSo ps1, PhanSo ps2, PhanSo ps3, PhanSo ps4){
    float Chia = ps1.Number/ps2.Number/ps3.Number/ps4.Number;
    return Chia;
}

int main(){
    PhanSo ps1(7,9), ps2(11,2), ps3(4,8), ps4(5,2);

    float phep_cong = ps1.PhepToan_Cong(ps1, ps2, ps3, ps4);
    printf("Ket qua phep toan Cong: %.4f\n", phep_cong);

    float phep_tru = ps1.PhepToan_Tru(ps1, ps2, ps3, ps4);
    printf("Ket qua phep toan Tru: %.4f\n", phep_tru);

    float phep_nhan = ps1.PhepToan_Nhan(ps1, ps2, ps3, ps4);
    printf("Ket qua phep toan Nhan: %.4f\n", phep_nhan);

    float phep_chia = ps1.PhepToan_Chia(ps1, ps2, ps3, ps4);
    printf("Ket qua phep toan Chia: %.4f", phep_chia);

    return 0;
}
