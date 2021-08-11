//
// Created by yuanYue on 2021/8/07.
//

#include "../Inc/LCD1602.h"

volatile  u8 position = 0x80;

void LCD1602::writeComd(u8 comd) {
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);

    DATA_PORT->ODR = comd;

    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
}

void LCD1602::writeData(u8 data) {
    HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);

    DATA_PORT->ODR = data;

    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);


    if (position == 0x8F) {
        HAL_GPIO_TogglePin(LED_0_GPIO_Port, LED_0_Pin);
        writeComd(0xc0);
        position = 0xc0;
        return;
    }
    position++;

}

void LCD1602::writeText(u8 *text) {
    while ((*text) != 0) {
        writeData(*text);
        text++;
    }
}

void LCD1602::deleteData() {
    if (position == 0x80)return;
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

void LCD1602::makeCursor(u8 cfg) {
    //0；flash 1:stop flash
    if (cfg >= 2) {
        writeComd(0x0c);
        return;
    }
    writeComd(0x0f - cfg);
}

void LCD1602::placeText(u8 x, u8 y, u8 *text) {
    if (y) position = 0xC0;
    position += x;
    writeComd(position);
    while ((*text) != 0) {
        writeData(*text);
        text++;
    }
}

LCD1602::LCD1602(u8 x, u8 y, GPIO_TypeDef *DATA_PORT) {
    this->x = x;
    this->y = y;
    this->DATA_PORT = DATA_PORT;

    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
    if (y) position = 0xC0;
    position += x;
    writeComd(0x38);
    writeComd(0x0c);
    writeComd(0x06);
    writeComd(0x01);
    writeComd(position);
    HAL_Delay(2);
}
