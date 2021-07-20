# STM32-HAL-LCD1602-Driver
基于STM32 HAL库的LCD1602驱动

LCD1602 driver based on STM32 HAL library

## 基本使用：
``` C
#include  "LCD1602.h" 

initLCD(1);
writeData(0x41);
```
## 方法说明：
- ```void initLCD(uint8_t position)```		*初始化LCD position->显示位置*
- ```void writeComd(uint8_t comd)``` 		*写指令*
- ```void writeData(uint8_t data)```		*写数据*
- ```void deleteData()```					*删除一位*
- ```void showCursor(uint8_t stopFlash)```	*显示光标 stopFLash->0:光标闪烁 1:光标不闪烁*
- ```void closeCursor()```					*关闭光标*