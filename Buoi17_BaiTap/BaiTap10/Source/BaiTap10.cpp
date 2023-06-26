#include <cstdio>
#include <cstring>

class Sach {
    private:
        char tenSach[100];
        char tacGia[100];
        int namXuatBan;
        int soLuong;

    public:
        Sach(const char* ten, const char* tacGia, int namXuatBan, int soLuong);
        void inThongTin();
        void muonSach(int soLuongMuon);
        void traSach(int soLuongTra);
};

Sach::Sach(const char* ten, const char* tacGia, int namXuatBan, int soLuong) {
    strcpy(tenSach, ten);
    strcpy(this->tacGia, tacGia);
    this->namXuatBan = namXuatBan;
    this->soLuong = soLuong;
}

void Sach::inThongTin() {
    printf("Thong tin sach:\n");
    printf("Ten sach: %s\n", tenSach);
    printf("Tac gia: %s\n", tacGia);
    printf("Nam xuat ban: %d\n", namXuatBan);
    printf("So luong: %d\n", soLuong);
    printf("-----------------------\n");
}

void Sach::muonSach(int soLuongMuon) {
    if (soLuong >= soLuongMuon) {
        soLuong -= soLuongMuon;
        printf("Da muon %d quyen sach '%s'. So luong sach con lai: %d\n", soLuongMuon, tenSach, soLuong);
    } else {
        printf("Khong du so luong sach '%s' de muon\n", tenSach);
    }
}

void Sach::traSach(int soLuongTra) {
    soLuong += soLuongTra;
    printf("Da tra %d quyen sach '%s'. So luong sach hien tai: %d\n", soLuongTra, tenSach, soLuong);
}

int main() {
    Sach sach1("Harry Potter", "J.K. Rowling", 1997, 10);
    Sach sach2("To Kill a Mockingbird", "Harper Lee", 1960, 7);
    Sach sach3("The Great Gatsby", "F. Scott Fitzgerald", 1925, 3);

    sach1.inThongTin();
    sach2.inThongTin();
    sach3.inThongTin();

    sach1.muonSach(3);
    sach2.muonSach(5);
    sach3.muonSach(2);

    sach1.traSach(1);
    sach2.traSach(3);
    sach3.traSach(2);

    return 0;
}
