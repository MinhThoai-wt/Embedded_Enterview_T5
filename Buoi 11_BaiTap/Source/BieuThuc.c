#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hàm tính giá trị của biểu thức phép toán
int tinhGiaTriPhepToan(char* bieuThuc) {
    int ketQua = 0;         // Biến lưu trữ kết quả của phép toán
    int toanHang = 0;       // Biến lưu trữ giá trị của từng toán hạng
    char phepToanTruoc = '+';   // Biến lưu trữ phép toán trước đó (+ hoặc -)

    int doDai = strlen(bieuThuc);

    for (int i = 0; i < doDai; i++) {
        if (bieuThuc[i] >= '0' && bieuThuc[i] <= '9') {
            toanHang = toanHang * 10 + (bieuThuc[i] - '0');   // Xây dựng giá trị của toán hạng
        } 

        else if (bieuThuc[i] == '+' || bieuThuc[i] == '-' || bieuThuc[i] == '*' || bieuThuc[i] == '/') {
            if (phepToanTruoc == '+') {
                ketQua += toanHang;   // Thực hiện phép toán cộng với toán hạng trước đó
            } else if (phepToanTruoc == '-') {
                ketQua -= toanHang;   // Thực hiện phép toán trừ với toán hạng trước đó
            } else if (phepToanTruoc == '*') {
                ketQua *= toanHang;   // Thực hiện phép toán nhân với toán hạng trước đó
            } else if (phepToanTruoc == '/') {
                ketQua /= toanHang;   // Thực hiện phép toán chia cho toán hạng trước đó
            }

            toanHang = 0;           // Đặt lại giá trị của toán hạng về 0
            phepToanTruoc = bieuThuc[i];   // Cập nhật phép toán trước đó
        } 
        
        else if (bieuThuc[i] == '(') {
            int j = i + 1;
            int dem = 1;

            // Tìm vị trí đóng ngoặc ')' tương ứng với ngoặc mở '('
            while (dem > 0 && j < doDai) {
                if (bieuThuc[j] == '(') {
                    dem++;
                } else if (bieuThuc[j] == ')') {
                    dem--;
                }
                j++;
            }

            char bieuThucCon[j - i - 2];
            strncpy(bieuThucCon, bieuThuc + i + 1, j - i - 2);
            bieuThucCon[j - i - 2] = '\0';

            int ketQuaCon = tinhGiaTriPhepToan(bieuThucCon);   // Đệ quy tính giá trị của biểu thức con

            if (phepToanTruoc == '+') {
                ketQua += ketQuaCon;    // Thực hiện phép toán cộng với kết quả của biểu thức con
            } else if (phepToanTruoc == '-') {
                ketQua -= ketQuaCon;    // Thực hiện phép toán trừ với kết quả của biểu thức con
            } else if (phepToanTruoc == '*') {
                ketQua *= ketQuaCon;    // Thực hiện phép toán nhân với kết quả của biểu thức con
            } else if (phepToanTruoc == '/') {
                ketQua /= ketQuaCon;    // Thực hiện phép toán chia cho kết quả của biểu thức con
            }

            i = j - 1;   // Cập nhật chỉ số i để bỏ qua phần đã tính toán trong biểu thức
        }
    }

    if (phepToanTruoc == '+') {
        ketQua += toanHang;   // Thực hiện phép toán cộng với toán hạng cuối cùng
    } else if (phepToanTruoc == '-') {
        ketQua -= toanHang;   // Thực hiện phép toán trừ với toán hạng cuối cùng
    } else if (phepToanTruoc == '*') {
        ketQua *= toanHang;   // Thực hiện phép toán nhân với toán hạng cuối cùng
    } else if (phepToanTruoc == '/') {
        ketQua /= toanHang;   // Thực hiện phép toán chia cho toán hạng cuối cùng
    }

    return ketQua;
}

int main() {
    char bieuThuc[] = "2 + 3 - (6 * 8)";
    int ketQua = tinhGiaTriPhepToan(bieuThuc);
    printf("Ket qua: %d\n", ketQua);

    return 0;
}
