#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int myAdd(int a, int b)
{
	printf("myAdd.......");
	return a + b;
}

int myAdd2(int a, int b)
{
	printf("myAdd2.......");
	return a + b;
}
int myAdd3(int a, int b)
{
	printf("myAdd3.......");
	return a + b;
}
int myAdd4(int a, int b)
{
	printf("myAdd4.......");
	return a + b;
}

typedef int(*myPointer)(int a, int b);

int MainOp(myPointer myFunction)
{
	int c = myFunction(8, 9);
	return c;
}

int MainOp2(int(*myPointer2)(int a, int b))
{
	int c = myPointer2(99, 100);
	return c;
}
int main()
{
	MainOp(myAdd);
	MainOp2(myAdd2);
	//遵守函数指针的协议，返回值类型，参数类型，参数个数
	//前人完全可以调用后来人写的代码
	printf("helloworld!\n");
	system("pause");
	return 0;
}