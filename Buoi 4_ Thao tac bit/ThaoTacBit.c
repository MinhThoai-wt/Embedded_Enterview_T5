#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000000;
uint8_t PORTB = 0b11111111;


typedef enum{
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8
}s_pins;


void readByte(uint8_t byte){
    uint8_t temp;
    printf("0b");
    for(uint8_t i=0;i<8;i++){
        temp=byte & 0b10000000; 
        if(temp!=0){
            printf("1");

        }
        else{
            printf("0");
        }
        byte=byte<<1;
    }
    printf("\n");
}

void pinHigh(s_pins pin){
    PORTA=PORTA|(0b10000000>>pin);
    readByte(PORTA);
}

void pinLow(s_pins pin){
    PORTB=PORTB&~(0b10000000>>pin);
    readByte(PORTB);
}

int main(int argc, char const *argv){
    pinHigh(PIN6); //Xuat gia tri portA
    pinLow(PIN3);  //Xuat gia tri portB
    return 0;
}





