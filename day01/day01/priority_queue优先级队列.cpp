#include<iostream>
using namespace std;
#include"queue"
#include<functional>
void main81()
{
	priority_queue<int> p1;//Ĭ�����������
	priority_queue<int, vector<int>, less<int>> p2;//��ǰԤ����õĺ�����ν��
	priority_queue<int, vector<int>, greater<int>> p3;//��С���ȼ�

	p1.push(11);
	p1.push(88);
	p1.push(6);
	p1.push(99);

	cout << "top:" <<p1.top()<< endl;
	cout << "size:" << p1.size() << endl;

	while (!p1.empty())
	{
		cout << p1.top()<< " ";
		p1.pop();
	}
	cout <<"��С����" << endl;

	p3.push(11);
	p3.push(88);
	p3.push(6);
	p3.push(99);

	cout << "top:" << p3.top() << endl;
	cout << "size:" << p3.size() << endl;

	while (!p3.empty())
	{
		cout << p3.top() << " ";
		p3.pop();
	}
}
int main()
{
	main81();
	cout << "helloword" << endl;
	system("pause");
	return 0;
}