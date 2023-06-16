#include <iostream>
using namespace std;

class SinhVien{
    public:
        void hienThi(); //này được gọi là method (hay hàm trong C)
        void themThongTin(int tuoi, int lop);
    private:
        int tuoi; //này được gọi là property (hay biến trong C)
        int lop;
};

void SinhVien::hienThi(){
    cout<<"Tuoi: "<<tuoi<<endl;
    cout<<"Lop: "<<lop<<endl;
}

void SinhVien::themThongTin(int tuoi, int lop){
    SinhVien::tuoi = tuoi; //Nếu khai báo property trong private là int Tuoi thì chỉ cần: Tuoi = tuoi;
    SinhVien::lop = lop; 
}

int main(){
    SinhVien sv; //SinhVien được gọi là class, sv được gọi là object (trong C lần lượt là Kiểu dữ liệu và Biến)
    sv.themThongTin(16, 7);
    sv.hienThi();

    return 0;
}