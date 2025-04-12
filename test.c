#include <stdio.h>

void showByte(unsigned char* p, int size){
	for(int index=size-1;index>=0;index--){
		unsigned char j=0b10000000;
		for(int i=0;i<8;i++){
			((*(p+index))&j)?putchar('1'):putchar('0');
			j=j>>1;
		}	
		printf("   ");
		}	
		printf("\n");
}
int main(){
	char type;
	int size;
	unsigned char* p;
	printf("请选择数据类型：（1.退出 2.int 3.float 4.double）:\n");
	do{
	type=getchar();
	switch(type){
	case '1':
	   break;

	case '2':
		printf("请输入整数: ");
		int iDigit;
		scanf("%d",&iDigit);
		size=sizeof(iDigit);
		showByte((unsigned char*)&iDigit,size);
	   break;

	case '3':
		printf("请输入小数(float): ");
		float fDigit;
		scanf("%f",&fDigit);
		size=sizeof(fDigit);
		showByte((unsigned char*)&fDigit,size);
	   break;
	   
	case '4':
		printf("请输入小数(double): ");
		double dDigit;
		scanf("%lf",&dDigit);
		size=sizeof(dDigit);
		showByte((unsigned char*)&dDigit,size);
	   break;}
	}while (type!='1');
}
