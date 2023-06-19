#include <iostream>
#include <vector>

using namespace std;

/*void HienThi(){
    for(int i=0; i<array.size(); i++){
        printf("%d\n", array[i]);
    }
} */

int main(){
    vector<int> array;
    array.push_back(4);
    array.push_back(8);
    array.push_back(20);
    array.push_back(15);

    array.insert(array.begin()+2, 100); //chèn phần tử mới (100) vào vị trí thứ 3

    array.pop_back(); //xóa phần tử cuối


    for(int i=0; i<array.size(); i++){
        printf("%d\n", array[i]);
    }

    array.assign(7,0); //Gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ.
    for(int item : array){  //Vòng lặp for kiểu khác
        printf("i = %d\n", item);
    }

    return 0;
    array.clear(); //loại bỏ tất cả các phần tử của vùng chứa vector
}