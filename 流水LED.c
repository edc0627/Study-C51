// 使用程序前，将J13调整为IO模式（2-3脚短接）
#include "reg52.h"
// #include "absacc.h"

sbit HC138_A=P2^5;
sbit HC138_B=P2^6;
sbit HC138_C=P2^7;

// 关闭外设
//void Cls_Peripheral(void)
//{ // IO模式（J13-2和J13-3相连）
//  P0 = 0xFF;
//  P2 = P2 & 0x1F | 0x80;			// P27~P25清零，再定位Y4C
//  P2 &= 0x1F;						// P27~P25清零
//  P0 = 0;
//  P2 = P2 & 0x1F | 0xA0;			// P27~P25清零，再定位Y5C
//  P2 &= 0x1F;						// P27~P25清零
////XBYTE[0x8000] = 0xFF;				// MM模式（J13-2和J13-1相连）
////XBYTE[0xA000] = 0;
//}

// 延时函数（最小约1ms@12MHz）
void Delay(unsigned int num)
{
  unsigned int i;
  while(num--)
    for(i=0; i<628; i++);
}

//流水LED
void Led_Running()
{ // IO模式（J13-2和J13-3相连）
	unsigned int i;
	HC138_A=0;
	HC138_B=0;
	HC138_C=1;
	
	for(i=0;i<=3;i++)
	{
		P0=0x00;
		Delay(1000);
		P0=0xff;
		Delay(1000);
	}
	for(i=1;i<=8;i++)
	{
		P0=0xff<<i;
		Delay(100);
	}
	for(i=1;i<=8;i++)
	{
		P0=~(0xff<<i);
		Delay(100);
	}
}

// 主函数
void main(void)
{
  while(1)
  {
		Led_Running();
  }
}
