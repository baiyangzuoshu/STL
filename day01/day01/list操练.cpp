#include<iostream>
using namespace std;
#include"list"

void main72()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_front(i);
	}

	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "size:"<<l.size()<<endl;

	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.begin();
	it2++;
	it2++;
	it2++;

	l.erase(it2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "size:" << l.size() << endl;
	it1 = l.begin();
	it2 = l.begin();
	it2++;
	it2++;
	it2++;
	l.erase(it1,it2);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "size:" << l.size() << endl;

	l.insert(l.begin(), 100);
	l.insert(l.begin(), 200);
	l.insert(l.begin(), 300);
	l.insert(l.begin(),100);
	l.remove(100);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "size:" << l.size() << endl;
}

int main()
{
	main72();
	cout << "helloword" << endl;
	system("pause");
	return 0;
}