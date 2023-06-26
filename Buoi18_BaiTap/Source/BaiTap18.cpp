#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum{
    NAM,
    NU
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

class SinhVien{
    private:
        uint8_t ID;
        string TEN;
        float TOAN;
        TypeGioiTinh GIOI_TINH;
        TypeHocLuc HOC_LUC;
    public:
        SinhVien(string ten, TypeGioiTinh gioi_tinh, float toan);
        uint8_t getID();
        float getDiemTB();
};

SinhVien::SinhVien(string ten, TypeGioiTinh gioi_tinh, float toan){
    static uint8_t id=100;
    ID = id;
    id++;
};

uint8_t SinhVien::getID(){
    return this->ID;
    //hoặc return SinhVien::ID
}

class Menu{
    private:
        list<SinhVien> Database;
    public:
        void themSinhVien();
        void capNhatThongTin();
};

void Menu::themSinhVien(){
    string ten;
    float diemToan;

    SinhVien sv(....);

    Database.push_back(sv);
}

void Menu::CapNhatThongTin(){
    uint8_t id;
    //
    for(SinhVien item : Database){
        if(item.getID()==id){
            //Tìm thấy thông tin
            break
        }
    }
    //Không tìm thấy
}

int main(){
    
}