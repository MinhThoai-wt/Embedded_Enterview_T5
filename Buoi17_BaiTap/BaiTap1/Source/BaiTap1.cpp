#include <stdio.h>
#include <cstdint>
#include <cmath>

class Diem {
    private:
        int8_t toaDoX;
        int8_t toaDoY;

    public:
        Diem(int8_t x = 0, int8_t y = 0);
        void setToaDoX(int8_t x);
        int8_t getToaDoX();
        int8_t getToaDoY();
};

Diem::Diem(int8_t x, int8_t y) {
    toaDoX = x;
    toaDoY = y;
}

void Diem::setToaDoX(int8_t x) {
    toaDoX = x;
}

int8_t Diem::getToaDoX() {
    return toaDoX;
}

int8_t Diem::getToaDoY() {
    return toaDoY;
}

class PhepToanOXY {
    private:
        Diem diemA;
        Diem diemB;
        Diem diemC;
        enum TypePhepToan {
            KHOANG_CACH,
            DIEN_TICH_TAM_GIAC
        };

        TypePhepToan phepToan;

    public:
        PhepToanOXY(Diem A, Diem B);
        PhepToanOXY(Diem A, Diem B, Diem C);
        float getKhoangCach();
        float getDienTich();
};

PhepToanOXY::PhepToanOXY(Diem A, Diem B) {
    phepToan = KHOANG_CACH;
    diemA = A;
    diemB = B;
}

PhepToanOXY::PhepToanOXY(Diem A, Diem B, Diem C) {
    phepToan = DIEN_TICH_TAM_GIAC;
    diemA = A;
    diemB = B;
    diemC = C;
}

float PhepToanOXY::getKhoangCach() {
    if (phepToan == KHOANG_CACH) {
        int8_t xDiff = diemB.getToaDoX() - diemA.getToaDoX();
        int8_t yDiff = diemB.getToaDoY() - diemA.getToaDoY();
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    } else {
        printf("Khong goi duoc ham tinh khoang cach\n");
        return 0.0f;
    }
}

float PhepToanOXY::getDienTich() {
    if (phepToan == DIEN_TICH_TAM_GIAC) {
        int8_t x1 = diemA.getToaDoX();
        int8_t y1 = diemA.getToaDoY();
        int8_t x2 = diemB.getToaDoX();
        int8_t y2 = diemB.getToaDoY();
        int8_t x3 = diemC.getToaDoX();
        int8_t y3 = diemC.getToaDoY();

        float dienTich = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        return dienTich;
    } else {
        printf("Khong goi duoc ham tinh dien tich tam giac\n");
        return 0.0f;
    }
}

int main() {
    Diem A(0, 0);
    Diem B(3, 4);
    Diem C(6, 0);

    PhepToanOXY phepToanAB(A, B);
    float khoangCachAB = phepToanAB.getKhoangCach();
    printf("Khoang cach AB: %.2f\n", khoangCachAB);

    PhepToanOXY phepToanABC(A, B, C);
    float dienTichABC = phepToanABC.getDienTich();
    printf("Dien tich ABC: %.2f\n", dienTichABC);

    return 0;
}
