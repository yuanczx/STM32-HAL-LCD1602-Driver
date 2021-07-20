# STM32-HAL-LCD1602-Driver
基于STM32 HAL库的LCD1602驱动

LCD1602 driver based on STM32 HAL library

## 注意：
- 使用前请正确配置*User Label* 如RW引脚对应*User Label*应设置成"RW"

## 基本使用：
``` C
#include  "LCD1602.h" 
...

void main()
{
	initLCD(0,GPIOX);
	writeData(0x41);
	while(1);
}
```
## 方法说明：
- ```void initLCD(u8 position,GPIO_TypeDef* DATA_PORT)```	*初始化LCD position->显示位置 DATA_PORT->数据端口*
- ```void writeComd(u8 comd)``` 		*写指令*
- ```void writeData(u8 data)```		*写数据*
- ```void deleteData()```					*删除一位*
- ```void showCursor(u8 stopFlash)```	*显示光标 stopFLash->0:光标闪烁 1:光标不闪烁*
- ```void closeCursor()```					*关闭光标*