#include "reg52.h"
#include "intrins.h" //左右移位

typedef unsigned int uint;

#define LED P0
uint i;
/*************************************************
   					延时函数
*************************************************/
void delay(unsigned char c){//延时c ms
	unsigned char a=2, b=142;
	for(c; c>0; c--)
		for(; b>0; b--)
			for(; a>0; a--);
}
/*************************************************
					 主函数
--------------------------------------------------
功能：LED流水灯依次从右向左亮起，再从左向右亮起
*************************************************/	 
void main(){
	//LED = 0x7f;//0111 1111
	//delay(300);
	while(1){
		for(i=0; i<=7; i++){
			LED = _cror_(0x7f,i);//右移位
			delay(50000);	
		}
		for(i=0; i<=7; i++){
			LED = _crol_(0xfe,i);//左移位
			delay(50000);
		}
	}	
}

/*************************************************
					测试
**************************************************/
/*
void main(){
	unsigned int cnt = 0;
	while(1){
		//LED = ~(0x01<<cnt);
		//for(i=0; i<30000; i++);

		//测试
		LED = 0x7f;//0111 1111
		delay(300);
		LED = 0xbf;//1011 1111
		delay(300);
		LED = 0xbf >> 1;
		delay(300);

		for(cnt=1;cnt<=5;cnt++){
			LED = _cror_(0xdf,cnt); //_cror_(<被移位的数>,<移动的位数>)
			delay(300);
		}
	}
}
		
	   /*移位函数的错误用法

		
		LED = _cror_(LED,1);
		delay(300);
		LED = _cror_(LED,1);
		delay(300);
		LED = _cror_(LED,1);
		delay(300);
		LED = _cror_(LED,1);
		delay(300);
		*/
	 
