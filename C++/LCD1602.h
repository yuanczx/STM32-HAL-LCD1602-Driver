//
// Created by yuanczx on 2021/8/07.
//
#ifndef LCD_LCD1602_H
#define LCD_LCD1602_H
#ifdef __cplusplus
extern "C" {
#endif
#include "gpio.h"
typedef unsigned char u8;
class LCD1602 {
private:
    u8 x = 0, y = 0;
    GPIO_TypeDef *DATA_PORT;
public:
    LCD1602(u8 x, u8 y, GPIO_TypeDef *DATA_PORT);
    void writeComd(u8);//写指令
    void writeData(u8);//写数据
    void deleteData();//删除一位
    void makeCursor(u8);//显示光标 参数为光标是否闪烁 0：光标闪烁 1：光标不闪烁 2:关闭光标
    void writeText(u8 *);
    void placeText(u8, u8, u8 *);
};
#ifdef __cplusplus
}
#endif
#endif //LCD_LCD1602_H
