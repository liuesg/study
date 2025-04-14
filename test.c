#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
void showHex(unsigned char* cp,int size){
	if(4==size){
		//unsigned int* p = (unsigned int*)(void*)cp;
		//printf("%#X\n", *p);
		uint32_t num;
		memcpy(&num, cp, sizeof(num));  // 安全复制 4 字节
		printf("0x%08" PRIx32 "\n", num);}

	if(8==size){
		 uint64_t num = *(uint64_t*)cp;
		 memcpy(&num, cp, sizeof(num));  // 安全复制 8字节
                 printf("0x%016" PRIx64 "\n", num);
	}
}

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
		showHex(p,size);
		printf("\n");
}

int main(){
	char type;
	int size;
	unsigned char* p;
	do{
	printf("请选择数据类型：（1.退出 2.int 3.float 4.double）:\n");
	//type=getchar();注意getchar和scanf的区别，getchar会多一个换行，导致多打印一行菜单
   	scanf(" %c", &type);
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
