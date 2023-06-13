#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    public:
        void setThongTin(string ten, int tuoi);
        void hienThi();
    protected:
        int TUOI;
        string TEN;
};

void DoiTuong::hienThi(){
    cout<<"Day la class DoiTuong\n";
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Lop: "<<TUOI<<endl;
};

void DoiTuong::setThongTin(string ten, int tuoi){
    TEN = ten;
    TUOI = tuoi;
};

class SinhVien : public DoiTuong{
    public:
        void setThongTin(string ten, int tuoi, int mssv);
        void hienThi();
    private:
        int MSSV;
};

void SinhVien::setThongTin(string ten, int tuoi, int mssv){
    TEN = ten;
    TUOI =tuoi;
    MSSV =mssv;
};

void SinhVien::hienThi(){
    cout<<"Day la class SinhVien\n";
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Lop: "<<TUOI<<endl;
    cout<<"MSSV: "<<MSSV<<endl;
}

int main(){
    DoiTuong dt;
    dt.setThongTin("Hoang", 17);
    dt.hienThi();

    SinhVien sv;

    sv.setThongTin("Toan", 15, 1001);
    sv.hienThi();

    return 0;
}
