## 应该还会加点功能
## 基本使用：
``` C
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