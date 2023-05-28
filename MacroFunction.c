#include <stdio.h>

#define MAX 105

#define SUM(a,b) a+b

#define CREATE_FUNC(ten_ham, noi_dung) \
void ten_ham(){                        \
    printf("%s\n", noi_dung);          \
}

CREATE_FUNC(text1,"this is text1\n");
CREATE_FUNC(text2,"this is text2\n");


int main(){
    printf("MAX: %d\n", MAX);

    int a=MAX+5;
    printf("Tong a va b: %d\n",SUM(4,7));

    text1();
    text2();

    return 0;
}