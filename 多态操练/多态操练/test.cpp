#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int& c = a;
	c = b;
	printf("a:%d",a);
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}