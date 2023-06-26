#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        string TEN;
        int NamSinh;
        string DiaChi;
    public:
        void In_ThongTin(string ten, int nam_sinh, string dia_chi);
        int TinhTuoi();
        int Nam_Hien_Tai = 2023;
};

void Person::In_ThongTin(string ten, int nam_sinh, string dia_chi){
    TEN = ten;
    NamSinh = nam_sinh;
    DiaChi = dia_chi;

    printf("In Thong Tin:\n");
    printf(" + Ten: %s\n", TEN.c_str());
    printf(" + Nam sinh: %d\n", NamSinh);
    printf(" + Dia chi: %s\n", DiaChi.c_str());
}

int Person::TinhTuoi(){
    int Tuoi = Nam_Hien_Tai - NamSinh;
    printf("Tinh tuoi:\n");
    return Tuoi;
}

int main(){
    Person ps;
    ps.Nam_Hien_Tai = 2023;
    ps.In_ThongTin("Thoai", 1999, "Bac Lieu");

    printf(" Tuoi: %d", ps.TinhTuoi());

    return 0;
}