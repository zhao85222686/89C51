#include <reg52.h>

#define uchar unsigned char
#define uint unsigned int



sbit WE = P2^7;//数码管位选信号
sbit DU = P2^6;//数码管段选信号

void delay(uint i)
{
	uchar a,b;
	for(;i>0;i--)
	  for(b=102;b>0;b--)
        for(a=3;a>0;a--);
}

uchar code flashdisplay[]=		//显示数字
{
		 0x3f,  //0
		 0x06,  //1
		 0x5b,  //2
		 0x4f,  //3
		 0x66,  //4
		 0x6D,  //"5"
         0x7D,  //"6"
         0x07,  //"7"
         0x7F,  //"8"
         0x6F   //"9"
};

uchar code flashsite[]=		//显示数码管位置
{
		 0xfe,//1111 1110 第一位数码管 0
		 0xfd,//1111 1101 第二位数码管 1
		 0xfb,//1111 1011 第三位数码管 2
		 0xf7,//1111 0111 第四位数码管 3 万
		 0xef,//1110 1111 第五位数码管 4 千
		 0xdf,//1101 1111 第六位数码管 5 百
		 0xbf,//1011 1111 第七位数码管 6 十
		 0x7f //0111 1111 第八位数码管 7 个
};

void show (uint i)	 //设置数字为万位以内的数
{
	uchar ge,shi,bai,qian,wan;
	ge = i%10;
	shi = (i/10)%10;
	bai = (i/100)%10;
	qian = (1/1000)%10;
	wan = 1/10000;

	P0 =flashsite[3];		   //万位
	WE = 1;	 
	WE = 0; 
	P0 = flashdisplay[wan];
	DU = 1;
	DU = 0;
	delay(2); 

	P0 =flashsite[4];		   //千位
	WE = 1;	 
	WE = 0; 
	P0 = flashdisplay[qian];
	DU = 1;
	DU = 0;
	delay(2); 

	P0 =flashsite[5];		   //百位
	WE = 1;	 
	WE = 0; 
	P0 = flashdisplay[bai];
	DU = 1;
	DU = 0;
	delay(2); 

	P0 =flashsite[6];		   //十位
	WE = 1;	 
	WE = 0; 
	P0 = flashdisplay[shi];
	DU = 1;
	DU = 0;
	delay(2); 

	P0 =flashsite[7];		   //个位
	WE = 1;	 
	WE = 0; 
	P0 = flashdisplay[ge];
	DU = 1;
	DU = 0;
	delay(2); 
}


void main ()
{
	show(500);

}
