//
// Created by yuanYue on 2021/7/19.
//

#include "LCD1602.h"

GPIO_TypeDef *GPIOP;
volatile static u8 position = 0x80;

void initLCD(u8 x,u8 y, GPIO_TypeDef *DATA_PORT) {
    GPIOP = DATA_PORT;
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
    if (y) position=0xC0;
    position+=x;
    writeComd(0x38);
    writeComd(0x0c);
    writeComd(0x06);
    writeComd(0x01);
    writeComd(position);
    HAL_Delay(2);

}

void writeComd(u8 comd) {
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 0);
    HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, 0);

    GPIOP->ODR = comd;

    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);
}

void writeData(u8 data) {
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, 1);
    HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, 0);

    GPIOP->ODR = data;

    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 1);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, 0);

    if (position == 0x8F) {
        writeComd(0xc0);
        position = 0xc0;
        return;
    }
    position++;

}

void writeText(u8 *text) {
    while ((*text) != 0) {
        writeData(*text);
        text++;
    }
}

void deleteData() {
    if (position==0x80)return;
    writeComd(0x10);
    position--;
    writeData(0x01);
    writeComd(0x10);
    if (position == 0xc0) {
        writeComd(0x8f);
        writeData(0x01);
        writeComd(0x10);
        position = 0x8f;
        return;
    }
    position--;
}

void makeCursor(u8 cfg) {
    //0；flash 1:stop flash
    if (cfg >= 2) {
        writeComd(0x0c);
        return;
    }
    writeComd(0x0f - cfg);
}

void placeText(u8 x, u8 y, u8 *text) {
    if (y) position = 0xC0;
    position += x;
    writeComd(position);
    while ((*text) != 0) {
        writeData(*text);
        text++;
    }
}