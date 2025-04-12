#include <stdio.h>
int main(){
	char type;
	int size;
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
	   	printf("2,%d\n",size);
	   break;

	case '3':
		printf("请输入小数(float): ");
		float fDigit;
		scanf("%f",&fDigit);
		size=sizeof(fDigit);
	   	printf("3,%d\n",size);
	   break;
	   
	case '4':
		printf("请输入小数(double): ");
		double dDigit;
		scanf("%lf",&dDigit);
		size=sizeof(dDigit);
	   	printf("4,%d\n",size);
	   break;}
	}while (type!='1');
}
