#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main0101()
{
	int a[10];
	//����һ����������
	{
		typedef int (typeArray)[10];
		typeArray myArray;
		myArray[0] = 10;
		printf("myArray:%d\n",myArray[0]);
	}
	//����һ��ָ����������
	{
		typedef int (*PTypeArray)[10];
		PTypeArray myArray;
		myArray = &a;
		(*myArray)[0] = 20;
		printf("myArray:%d\n",a[0]);
	}
	//����һ��ָ���������͵�ָ�룬������ָ��
	{
		int(*myPointer)[10];
		myPointer = &a;
		(*myPointer)[0] = 100;
		printf("myArray:%d\n", a[0]);
	}
}
int main0001()
{
	main0101();
	printf("helloworld!");
	system("pause");
	return 0;
}