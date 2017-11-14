#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int a, int b)
{
	return a + b;
}
int main01()
{
	add(1, 2);//直接调用

	//定义一个函数类型
	{
		typedef int (myFunction)(int a, int b);
		myFunction *myAdd = NULL;
		myAdd = &add;
		myAdd(3, 4);

		myAdd = add;//c历史遗留的问题
		myAdd(8, 9);
	}
	//定义一个指针函数类型
	{
		typedef int(*myPointer)(int a, int b);
		myPointer myAdd = &add;
		myAdd(88, 99);
	}
	//函数指针
	{
		int(*myPointer)(int a, int b);
		myPointer = &add;
		myPointer(99, 88);
	}
	printf("helloworld!\n");
	system("pause");
	return 0;
}