#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int a, int b)
{
	return a + b;
}
int main01()
{
	add(1, 2);//ֱ�ӵ���

	//����һ����������
	{
		typedef int (myFunction)(int a, int b);
		myFunction *myAdd = NULL;
		myAdd = &add;
		myAdd(3, 4);

		myAdd = add;//c��ʷ����������
		myAdd(8, 9);
	}
	//����һ��ָ�뺯������
	{
		typedef int(*myPointer)(int a, int b);
		myPointer myAdd = &add;
		myAdd(88, 99);
	}
	//����ָ��
	{
		int(*myPointer)(int a, int b);
		myPointer = &add;
		myPointer(99, 88);
	}
	printf("helloworld!\n");
	system("pause");
	return 0;
}