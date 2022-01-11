#include "reg52.h"
#include "intrins.h" //������λ

typedef unsigned int uint;

#define LED P0
uint i;
/*************************************************
   					��ʱ����
*************************************************/
void delay(unsigned char c){//��ʱc ms
	unsigned char a=2, b=142;
	for(c; c>0; c--)
		for(; b>0; b--)
			for(; a>0; a--);
}
/*************************************************
					 ������
--------------------------------------------------
���ܣ�LED��ˮ�����δ������������ٴ�����������
*************************************************/	 
void main(){
	//LED = 0x7f;//0111 1111
	//delay(300);
	while(1){
		for(i=0; i<=7; i++){
			LED = _cror_(0x7f,i);//����λ
			delay(50000);	
		}
		for(i=0; i<=7; i++){
			LED = _crol_(0xfe,i);//����λ
			delay(50000);
		}
	}	
}

/*************************************************
					����
**************************************************/
/*
void main(){
	unsigned int cnt = 0;
	while(1){
		//LED = ~(0x01<<cnt);
		//for(i=0; i<30000; i++);

		//����
		LED = 0x7f;//0111 1111
		delay(300);
		LED = 0xbf;//1011 1111
		delay(300);
		LED = 0xbf >> 1;
		delay(300);

		for(cnt=1;cnt<=5;cnt++){
			LED = _cror_(0xdf,cnt); //_cror_(<����λ����>,<�ƶ���λ��>)
			delay(300);
		}
	}
}
		
	   /*��λ�����Ĵ����÷�

		
		LED = _cror_(LED,1);
		delay(300);
		LED = _cror_(LED,1);
		delay(300);
		LED = _cror_(LED,1);
		delay(300);
		LED = _cror_(LED,1);
		delay(300);
		*/
	 
