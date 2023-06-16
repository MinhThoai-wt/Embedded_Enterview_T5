#include <iostream>
using namespace std;

class SinhVien{
    public:
        SinhVien();
        void hienThi(); //này được gọi là method (hay hàm trong C)
    private:
        int tuoi; //này được gọi là property (hay biến trong C)
        int lop;
};

void SinhVien::hienThi(){
    cout<<"Tuoi: "<<tuoi<<endl;
    cout<<"Lop: "<<lop<<endl;
};

SinhVien::SinhVien(){
    SinhVien::tuoi = 19;
    SinhVien::lop = 3;
};

int main(){
    SinhVien sv; //Do khai báo Method trùng tên với tên Class và Method có tham số vào nên object sv cần phải có tham số vào
    sv.hienThi();

    return 0;
}