//
// Created by yuanczx on 2021/7/19.
//
#include "gpio.h"
#ifndef LCD_LCD1602_H
#define LCD_LCD1602_H

typedef unsigned char u8;
void initLCD(u8,GPIO_TypeDef*);//初始化LCD  参数为显示位置 如 0 表示 第一行第一列
void writeComd(u8);//写指令
void writeData(u8);//写数据
void deleteData();//删除一位
void makeCursor(u8);//显示光标 参数为光标是否闪烁 0：光标闪烁 1：光标不闪烁 2:关闭光标
void writeText(u8*);
#endif //LCD_LCD1602_H