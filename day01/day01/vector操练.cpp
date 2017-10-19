#include<iostream>
using namespace std;
#include"vector"
void main31()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(9);

	cout << "size:" << v1.size() << endl;
	cout << "front:" << v1.front() << endl;

	v1.front() = 100;
	v1.back() = 200;

	while (v1.size())
	{
		cout << "back:"<<v1.back() << endl;
		v1.pop_back();
	}
}

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it) << " ";
	}
}

void main32()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(10);

	vector<int> v2 = v1;

	vector<int> v3(v1.begin(), v1.begin() + 2);

	cout << "v1:";
	printVector(v1);
	cout << "v3:";
	printVector(v3);
}

void main33()
{
	vector<int> v1(10);//用数组的方式初始化需要指定长度
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 100;
	}

	printVector(v1);
}

void main34()
{
	vector<int> v1(10);//用数组的方式初始化需要指定长度
	for (int i = 0; i < 10; i++)
	{
		v1[i] = i + 100;
	}

	v1.push_back(100);
	v1.push_back(200);

	cout << "size:" <<v1.size()<< endl;
	printVector(v1);
}

void main35()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		v[i] = i;
	}

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it;
	}
	cout << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
}

void main36()
{
	vector<int> v(10);

	for (int i = 0; i < 10; i++)
	{
		v[i] = i;
	}

	v.erase(v.begin(), v.begin() + 2);
	printVector(v);

	v.erase(v.begin());
	printVector(v);
	cout << endl;

	v[1] = 2;
	v[3] = 2;
	printVector(v);
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it == 2)
		{
			it = v.erase(it);
		}
		else
		{
			it++;
		}
	}
	cout << endl;
	printVector(v);
	v.insert(v.begin(), 100);
	v.insert(v.end(), 200);
	cout << endl;
	printVector(v);
}
int mainVetor()
{
	//main31();
	//main32();
	//main33();
	//main34();
	//main35();
	main36();
	cout << "vector" << endl;
	system("pause");
	return 0;
}
