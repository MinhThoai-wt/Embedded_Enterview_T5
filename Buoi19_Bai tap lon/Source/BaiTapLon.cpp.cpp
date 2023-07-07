#include <iostream>
#include <string>
#include <list>

using namespace std;

class MonAn{
    private:
        int ID; //ID của món ăn
        string TEN_MON; //Tên món
        int SO_LUONG; //Số lượng món
        int GIA; //giá
    public:
        void NhapMonAn(); //nhập món ăn
        void HienThiMonAn(); //Hiển thị món ăn
        int getID();
        void setID(int Id);
        void setTen(string ten);
        string getTen();
        void setGia(double gia);
        double getGia();
};

void MonAn::NhapMonAn(){
    string ten;
    int gia;

    cout<<"Ten mon an: ";
    cin>>ten;
    cout<<endl;

    cout<<"Gia: ";
    cin>>gia;
    cout<<endl;

    cout<<"--------------------------"<<endl;

    TEN_MON = ten;
    GIA = gia;
}

void MonAn::HienThiMonAn(){
    cout << "ID: "<<ID<<endl;
    cout << "Ten: "<<TEN_MON<<endl;
    cout <<"Gia: "<<GIA<<endl;
    cout << endl;
}

int MonAn::getID(){
    return ID;
}

void MonAn::setID(int id){
    ID = id;
}

void MonAn::setTen(string ten){
    TEN_MON = ten;
}

string MonAn::getTen(){
    return TEN_MON;
}

void MonAn::setGia(double gia){
    GIA = gia;
}

double MonAn::getGia(){
    return GIA;
}

class QuanLi{ //lớp quản lý
    private:
        list<MonAn> Data;
        int SO_BAN; //Số bàn
    public:
        void ThemMon(MonAn ma); //Thêm món
        void SuaMon(int id); //Sửa món
        void XoaMon(int id); //Xóa món
        void DanhSachMon(); //Danh sách món
        void ThietLapSoBan(); //Thiết lập số lượng bàn
        int getSoBan();
        void CapNhatID(); //Cập nhật ID
        list<MonAn> getData();
};

void QuanLi::ThemMon(MonAn ma){
    int Id = 1;
    if(!Data.empty()){
        MonAn MA = Data.back();
        Id = MA.getID() + 1;
    }
    ma.setID(Id);
    Data.push_back(ma);
    MonAn& mon_an = Data.back();
    mon_an.HienThiMonAn();
}

void QuanLi::SuaMon(int id){
    bool k = false;
    string ten;
    double gia;
    int LuaChon4_1;

    while(k == false){
        for(MonAn& ma : Data){
            if(ma.getID() == id){
                cout << "1. Sua ten" << endl;
                cout << "2. Sua gia" << endl;
                cout << "Nhap lua chon: " << endl;
                cin >> LuaChon4_1;
                cout << endl;

                if(LuaChon4_1 == 1){
                    cout<<"Sua ten: ";
                    cin>>ten;
                    cout<<endl;
                    ma.setTen(ten);
                }
                else if(LuaChon4_1 == 2){
                    cout<<"Sua gia: ";
                    cin>>gia;
                    cout<<endl;
                    ma.setGia(gia);
                    
                }
                else{
                    cout << "Lua chon khong hop le."<<endl;
                }
                k = true;
                break;
            }
            else{
                cout << "Danh sach khong co ID can tim" << endl; //Danh sách không có sinh viên cần tìm
            }
        }
    }
}

void QuanLi::XoaMon(int id){
    bool k = false;
    for(auto item = Data.begin(); item!=Data.end(); ++item){
        if(item->getID() == id){
            Data.erase(item);
            k = true;
            break;
        }
    }
    if(k==false){
        cout << "Danh sach khong co ID can tim" << endl; //Danh sách không có sinh viên cần tìm
    }
}

void QuanLi::DanhSachMon(){
    if(Data.empty()){
        cout << "Danh sach mon an trong" << endl;
    }
    else{
        for(MonAn& item : Data){
            item.HienThiMonAn();
        }
    }
}

void QuanLi::ThietLapSoBan(){
    int SoBan;
    cout << "Nhap so ban: ";
    cin >> SoBan;
    cout << endl;
    cout << "So ban: " << SoBan << endl;
    SO_BAN = SoBan;
}

int QuanLi::getSoBan(){
    return SO_BAN;
}

void QuanLi::CapNhatID(){
    int id = 1;
    for(MonAn& item : Data){
        item.setID(id);
        id++;
    }
}

list<MonAn> QuanLi::getData() {
    return Data;
}

class ThongTinBan{ //Thông tin bàn
    private:
        int SO_BAN;
        bool TRANG_THAI;
        typedef struct{
            MonAn MON_AN;
            int SO_LUONG;
        }TypeMonAn;
        list <TypeMonAn> DATABASE_MON_AN;
    public:
        ThongTinBan(int soBan, bool trangThai); 
        int getSoBan();
        bool getTrangThai();
        void danhSachMon();
        void themMon(QuanLi qL, MonAn mon, int soLuong, int id);
        void xuaMon(int id, int soLuong);
        void xoaMon(int id);
        void HienThi(TypeMonAn type_monAn);
};

/*void ThongTinBan::HienThi(TypeMonAn type_monAn){
    TypeMonAn typeMonAn;
    cout<<"So ban: "<<SO_BAN<<endl;
    cout<<"Thai: "<<TRANG_THAI<<endl;
    cout<<"ID: "<<ma.getID()<<endl;
    cout<<"Ten mon: "<<ma.getTen()<<endl;
    cout<<"Gia :"<ma.getGia()<<endl;
}*/

ThongTinBan::ThongTinBan(int soBan, bool trangThai){
    SO_BAN = soBan;
    TRANG_THAI = trangThai;
}

int ThongTinBan::getSoBan(){
    return SO_BAN;
}

bool ThongTinBan::getTrangThai(){
    return TRANG_THAI;
}

void ThongTinBan::danhSachMon(){
    //
}

void ThongTinBan::themMon(QuanLi qL, MonAn mon, int soLuong, int id){
    cout<<"Nhan vien them mon an: "<< endl;
    TypeMonAn kieuMon;
    for(MonAn& ma : qL.getData()){ //Lấy danh sách của class Quản Lý
        if(ma.getID() == id){
            kieuMon.MON_AN.setID(id);
            kieuMon.MON_AN.setTen(ma.getTen());
            kieuMon.MON_AN.setGia(ma.getGia());
            cout<<"Da them mon an"<<endl;
            cout<<"HIEN THI MON"<<endl;

            cout<<"ID: "<<id<<endl;
            cout<<"Ten mon: "<<ma.getTen()<<endl;
            cout<<"Gia mon: "<<ma.getGia()<<endl;
            cout<<"So luong: "<<soLuong<<endl;
        }
    }
}

class NhanVien{ //Lớp nhân viên
    private:
        list<MonAn> DATABASE_MON_AN;
        list<ThongTinBan> DATABASE_BAN;
    public:
        NhanVien(list<MonAn> database, int soBan);
        list<ThongTinBan> getData_NV();
};

NhanVien::NhanVien(list<MonAn> database, int soBan){
    DATABASE_MON_AN.assign(database.begin(), database.end()); //Gán phần tử

    for(int i=1; i<=soBan; i++){
        ThongTinBan ban(i, false);

        DATABASE_BAN.push_back(ban);
    }
}

list<ThongTinBan> NhanVien::getData_NV(){
    return DATABASE_BAN;
}

int main(){
    bool a = false, n = false;
    int LuaChon1, LuaChon2_1, LuaChon3_1, LuaChon2_2, LuaChon3_2; /*Nếu khai báo là int, vòng lặp while(b==false) sẽ lặp liên tục mà không
    đi vào thực thi switch(LuaChon1)*/
    int key = 0;
    MonAn MA;
    QuanLi QL;
    int id, soLuong;
    int BanCoKhach;
    while(a==false){
        bool b = false;
        cout << "1. Quan Li" <<endl;
        cout << "2. Nhan Vien" <<endl;
        cout <<"Nhap lua chon: ";
        cin >> LuaChon1;
        cin.ignore();
        cout << endl;
        while(b==false){
            bool c1 = false, c2 = false;
            switch (LuaChon1){
                case 1: {
                    cout << "1. Them mon" << endl;
                    cout << "2. Sua mon" << endl;
                    cout << "3. Xoa mon" << endl;
                    cout << "4. Danh sach mon" << endl;
                    cout << "5. Thiet lap so ban " << endl;
                    cout << "0. Quay lai" << endl;
                    cout << endl;
                    cout << "Nhap lua chon: ";
                    cin >> LuaChon2_1;
                    cin.ignore();
                    cout << endl;
                    while(c1==false){
                        switch (LuaChon2_1){
                            case 1:{
                                cout << "Them mon: " << endl;
                                MA.NhapMonAn();
                                QL.ThemMon(MA);
                                break;
                            }
                            case 2:{
                                cout << "Sua mon an: " << endl;
                                cout << "Nhap ID: ";
                                cin >> id;
                                cout <<endl;
                                QL.SuaMon(id);
                                QL.CapNhatID();
                                break;
                            }
                            case 3:{
                                cout << "Xoa mon an: " << endl;
                                cout << "Nhap ID: ";
                                cin >> id;
                                cout << endl;
                                if(n==true){
                                    id=id-1; 
                                    /*Vì khi xóa 1 đối tượng khỏi danh sách (trừ đối tượng cuối), các đối tượng bên tay phải sẽ
                                    lùi qua bên trái để thay thế vị trí của đối tượng đã xóa nên id cần giảm 1 đơn vị*/
                                }
                                QL.XoaMon(id);
                                QL.CapNhatID();
                                break;
                            }

                            case 4:{
                                cout << "Danh sach cac mon an: " << endl;
                                QL.DanhSachMon();
                                QL.CapNhatID();
                                break;
                            }

                            case 5:{
                                QL.ThietLapSoBan();
                                break;
                            }
                        }
                        if(LuaChon2_1 == 0){
                            c1 = true;
                            b = true;
                            continue;
                        }

                        cout << "1. Tiep tuc" <<endl;
                        cout << "0. Quay lai" <<endl;
                        cout <<"Nhap lua chon: ";
                        cin >> LuaChon3_1;
                        cout << endl;
                        if(LuaChon3_1 == 1){
                            c1 = false;
                            n = true;
                        }
                        else if(LuaChon3_1 == 0){
                            c1 = true;
                            n = false;
                        }
                        else{
                            cout<<"Lua chon khong hop le"<<endl;
                            c1 = true;
                        }
                    }
                    break;
                }

                case 2: {
                    NhanVien NV(QL.getData(), QL.getSoBan());
                    //ThongTinBan TTB(QL.getSoBan(), false);
                    cout<<"Chon ten so ban: ";
                    cin>>key;
                    cout<<endl;
                    //ThongTinBan TTB(key, true);
                    for(ThongTinBan& TTB : NV.getData_NV()){
                        if(TTB.getSoBan() == key){
                            cout<<"1. Them mon"<<endl;
                            cout<<"2. Sua mon" << endl;
                            cout<<"3. Xoa mon" << endl;

                            cout<<"Nhap lua chon: ";
                            cin>>LuaChon2_2;
                            cout<<endl;

                            while(c2==false){
                                switch (LuaChon2_2){
                                    case 1:{ //Thiết lập số bàn có khách
                                        cout<<"Nhap ID can tim";
                                        cin>> id;
                                        cout<<endl;

                                        cout<<"Nhap so luong mon an: ";
                                        cin>> soLuong;
                                        cout<<endl;
                                        TTB.themMon(QL, MA, soLuong, id);
                                        break;
                                    }
                                    case 2:{
                                        //TTB.xoaMon();
                                        break;
                                    }
                                    case 3:{
                                        break;
                                    }
                                    case 4:{
                            
                                        break;
                                    }
                                    case 5:{
                                        break;
                                    }
                                }

                                if(LuaChon2_2 == 0){
                                    c2 = true;
                                    b = true;
                                    continue;
                                }

                                cout << "1. Tiep tuc" <<endl;
                                cout << "0. Quay lai" <<endl;
                                cout <<"Nhap lua chon: ";
                                cin >> LuaChon3_2;
                                cout << endl;
                                if(LuaChon3_2 == 1){
                                    c2 = false;
                                    n = true;
                                }
                                else if(LuaChon3_2 == 0){
                                    c2 = true;
                                    n = false;
                                }
                                else{
                                    cout<<"Lua chon khong hop le"<<endl;
                                    c2 = true;
                                }
                            }
                        }
                    }
                    break;
                }
                default:
                    b == true;
                    break;
            }
        }
    }
}
