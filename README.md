# STM32-HAL-LCD1602-Driver
基于STM32 HAL库的LCD1602驱动

LCD1602 driver based on STM32 HAL library

## 注意：
- 使用前请使用CubeMX正确配置*User Label* 如RW引脚对应*User Label*应设置成"RW"

## 基本使用：
``` C
#include  "LCD1602.h" 
...

//显示Hello world!
void main()
{
	u8 text[] = "Hello world";
	initLCD(0,GPIOX);
	makeCursor(0);
	writeData(0x21);
	writeText(text);
	while(1);
}
```
## 方法说明：
- ```void initLCD(u8 position,GPIO_TypeDef* DATA_PORT)```	*初始化LCD position->显示位置 DATA_PORT->数据端口*
- ```void writeComd(u8 comd)``` 		*写指令*
- ```void writeData(u8 data)```		*写数据*- 
- ```void writeText(u8* text)```		*写文字*
- ```void deleteData()```					*删除一位*
- ```void makeCursor(u8 cfg)```	*cfg->0:光标闪烁 1:光标不闪烁 >2:关闭光标*