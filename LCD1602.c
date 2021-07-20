//
// Created by yuanczx on 2021/7/19.
//

#include "LCD1602.h"

GPIO_TypeDef* GPIOP;
void initLCD(u8 position,GPIO_TypeDef* DATA_PORT)
{
    GPIOP=DATA_PORT;
    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
    writeComd(0x38);
    writeComd(0x0c);
    writeComd(0x06);
    writeComd(0x01);
    writeComd(0x80+position);
    HAL_Delay(2);

}
void writeComd(u8 comd)
{
    HAL_GPIO_WritePin(RS_GPIO_Port,RS_Pin,0);
    HAL_GPIO_WritePin(RW_GPIO_Port,RW_Pin,0);

    GPIOP->ODR=comd;

    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
}

void writeData(u8 data)
{
    HAL_GPIO_WritePin(RS_GPIO_Port,RS_Pin,1);
    HAL_GPIO_WritePin(RW_GPIO_Port,RW_Pin,0);

    GPIOP->ODR=data;

    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,1);
    HAL_Delay(1);
    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,0);
}

void deleteData()
{
    writeComd(0x10);
    writeData(0x01);
    writeComd(0x10);
}

void showCursor(u8 stopFlash)
{
    //0；flash 1:stop flash
    writeComd(0x0f-stopFlash);
}

void closeCursor()
{
    writeComd(0x0c);
}