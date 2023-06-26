#include <iostream>
#include <string>

using namespace std;

class TaiKhoanNganHang{ //Tài khoản ngân hàng
    private:
        int SoTaiKhoan; //Số tài khoản
        string TenTaiKhoan; //Tên tài khoản
        int SoDu; //Số dư
    public:
        TaiKhoanNganHang(int so_tai_khoan, string ten_tai_khoan, int so_du);
        void RutTien(int Tien); //Rút tiền
        void NapTien(int Tien); //Nạp tiền
        int KiemTraSoDu(); //Kiểm tra số dư
};

TaiKhoanNganHang::TaiKhoanNganHang(int so_tai_khoan, string ten_tai_khoan, int so_du){
    SoTaiKhoan = so_tai_khoan;
    TenTaiKhoan = ten_tai_khoan;
    SoDu = so_du;

    printf("So tai khoan: %d\n", SoTaiKhoan);
    printf("Ten tai khoan: %s\n", TenTaiKhoan.c_str());
    printf("So du: %d\n", SoDu);
}

void TaiKhoanNganHang::RutTien(int Tien){
    SoDu = SoDu - Tien;
    printf("So tien duoc rut: %d\n", Tien);
}

void TaiKhoanNganHang::NapTien(int Tien){
    SoDu = SoDu + Tien;
    printf("So tien duoc nap: %d\n", Tien);
}

int TaiKhoanNganHang::KiemTraSoDu(){
    return SoDu;
}

int main(){
    TaiKhoanNganHang TK(1001, "PHAM MINH THOAI", 15000);
    TK.RutTien(3000);
    printf("So du: %d\n", TK.KiemTraSoDu());
    TK.NapTien(1000);
    printf("So du: %d\n", TK.KiemTraSoDu());

    return 0;
}

