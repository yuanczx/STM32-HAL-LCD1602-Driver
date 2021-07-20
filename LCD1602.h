//
// Created by yuanczx on 2021/7/19.
//

#include <stdint-gcc.h>

#ifndef LCD_LCD1602_H
#define LCD_LCD1602_H
void initLCD(uint8_t);//初始化LCD  参数为显示位置 如 0 表示 第一行第一列
void writeComd(uint8_t);//写指令
void writeData(uint8_t);//写数据
void deleteData();//删除一位
void showCursor(uint8_t);//显示光标 参数为光标是否闪烁 0：光标闪烁 1：光标不闪烁
void closeCursor(); //关闭光标
#endif //LCD_LCD1602_H
