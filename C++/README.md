## 应该还会加点功能
## 基本使用：
``` C++
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