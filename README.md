# STM32-LCD1602驱动
基于*STM32 HAL*库的*LCD1602*驱动

LCD1602 driver based on STM32 HAL library

## 注意：
- 使用前请使用CubeMX正确配置*User Label* 如RW引脚对应*User Label*应设置成"RW (也可以使用宏定义)"
- 在CubeMX的*Project Manager*中的*Code Generator*选项勾选*Generate peripheral initialization as a pair of.c/h files per peripheral*
- LCD1602的数据引脚应接到STM32引脚的高八位（若设置为低八位请左移八位）

## 基本使用：
``` C
C ：
#include  "LCD1602.h" 
...

//显示Hello world!
void main()
{
	u8 text[] = "Hello world";
  	initLCD(0,0,GPIOX);
  	makeCursor(0);
  	writeText(text);
  	writeData(0x21);
  	placeText(0,1,text);
  	writeData(0x21);
	while(1);
}
```
``` C++
C++ ：
#include  "LCD1602.h" 
...

//显示Hello world!
void main()
{
	u8 text[] = "Hello world";
  	LCD1602 lcd(0,0,GPIOB);
  	lcd.makeCursor(0);
  	lcd.writeText(text);
  	lcd.writeData(0x21);
  	lcd.placeText(0,1,text);
  	lcd.writeData(0x21);
	while(1);
}
```
## 方法说明：
- ```void initLCD(u8 x,u8 y,GPIO_TypeDef* DATA_PORT)```	*初始化LCD x->列 y:行 DATA_PORT->数据端口*
- ```void writeComd(u8 comd)``` 		*写指令*
- ```void writeData(u8 data)```		*写数据*- 
- ```void writeText(u8* text)```		*写文本*
- ```void placeText(u8 x,u8 y,u8* text)``` *x->列 y:行 text:文本*
- ```void deleteData()```					*删除*
- ```void makeCursor(u8 cfg)```	*cfg->0:光标闪烁 1:光标不闪烁 >2:关闭光标*