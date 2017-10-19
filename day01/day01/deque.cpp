#include<iostream>
#include"deque"
#include"algorithm"
using namespace std;

void printDeque(deque<int>& d)
{
	cout << endl;
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void main41()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(4);
	d1.push_back(5);

	d1.push_front(-1);
	d1.push_front(-4);
	d1.push_front(-9);
	d1.push_front(-8);

	cout << "front:" << d1.front() << " ";
	cout << "back:" << d1.back() << " ";

	printDeque(d1);

	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

	deque<int>::iterator it = find(d1.begin(), d1.end(), 1);
	if (it != d1.end())
	{
		cout << "distance:" << distance(d1.begin(), it);

	}
	else
	{
		cout << "no found!" << endl;
	}
}

int mainDeque()
{
	main41();
	cout << "helloword" << endl;
	system("pause");
	return 0;
}