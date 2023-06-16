#include <iostream>

class ToanHoc{
    public:
        void nhapABC();
        void getX1X2();
    private:
        int A;
        int B;
        int C;
        int X1;
        int X2;
};

namespace ConOngA{
    int A = 10;
}

namespace ConOngB{
    int A = 23;
}

int main(){
    printf("A = %d\n", ConOngA::A);
    printf("A = %d\n", ConOngB::A);
    return 0;
}