#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string, string> SinhVien;

    SinhVien["Ten"] = "Thoai";
    SinhVien["Tuoi"] = "24";
    SinhVien["MSSV"] ="709047";

    for(auto item : SinhVien){
        cout<<"Key: "<<item.first<<", "<<"value: "<<item.second<<endl;
    }

    return 0;
}