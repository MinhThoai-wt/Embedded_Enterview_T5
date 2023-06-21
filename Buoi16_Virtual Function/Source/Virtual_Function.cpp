#include <iostream>

class SinhVien{
    public:
    /*Nếu không dùng từ khóa "virtual", trong int main(), td.dislay sẽ lấy test của class cha chứ không phải class con*/
        virtual char *test(){ 
            return (char *)"Hello world\n";
        }

        void display(){
            printf("test: %s\n", test());
        }
};

class DoiTuong : public SinhVien{
    public:
        char *test(){
            return (char *)"This is test\n";
        }
};

int main(){
    SinhVien sv;
    sv.display();
    
    DoiTuong td;
    td.display();

    printf("abc: %s\n", td.test());
    return 0;
}