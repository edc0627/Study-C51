// ʹ�ó���ǰ����J13����ΪIOģʽ��2-3�Ŷ̽ӣ�
#include "reg52.h"
// #include "absacc.h"

sbit HC138_A=P2^5;
sbit HC138_B=P2^6;
sbit HC138_C=P2^7;

// �ر�����
//void Cls_Peripheral(void)
//{ // IOģʽ��J13-2��J13-3������
//  P0 = 0xFF;
//  P2 = P2 & 0x1F | 0x80;			// P27~P25���㣬�ٶ�λY4C
//  P2 &= 0x1F;						// P27~P25����
//  P0 = 0;
//  P2 = P2 & 0x1F | 0xA0;			// P27~P25���㣬�ٶ�λY5C
//  P2 &= 0x1F;						// P27~P25����
////XBYTE[0x8000] = 0xFF;				// MMģʽ��J13-2��J13-1������
////XBYTE[0xA000] = 0;
//}

// LED��ʾ
//void Led_Disp(unsigned char ucLed)
//{ // IOģʽ��J13-2��J13-3������
//  P0 = ~ucLed;
//  P2 = P2 & 0x1F | 0x80;			// P27~P25���㣬�ٶ�λY4C
//  P2 &= 0x1F;						// P27~P25����
////XBYTE[0x8000] = ~ucLed;			// MMģʽ��J13-2��J13-1������
//}

// ��ʱ��������СԼ1ms@12MHz��
void Delay(unsigned int num)
{
  unsigned int i;
  while(num--)
    for(i=0; i<628; i++);
}

void Led_Running()//��ˮLED
{ // IOģʽ��J13-2��J13-3������
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


// ������
void main(void)
{
//  unsigned char i, j;

//  Cls_Peripheral();

  while(1)
  { // 4�����ȵȼ�
//    for(i=0; i<4; i++)
//		for(j=0; j<100; j++)
//		{
//			Led_Disp(0xff);
//			Delay(i+1);
//			Led_Disp(0);
//			Delay(4-i);
//		}
		Led_Running();
  }
}