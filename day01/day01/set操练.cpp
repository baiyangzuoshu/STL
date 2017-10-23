#include<iostream>
using namespace std;
#include"set"
#include"functional"
//集合，元素唯一，自动排序（默认是从小到大），不能按照[]取值
//红黑树
void main91()
{
	set<int> s;
	for (int i = 0; i < 10; i++)
	{
		s.insert(rand());
	}
	s.insert(1000);
	s.insert(1000);
	s.insert(1000);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "size" << s.size() << endl;
	while (!s.empty())
	{
		set<int>::iterator it = s.begin();
		//error,set<int>::iterator it = s.end();
		cout << *it << " ";
		s.erase(it);
	}
	cout << "size" << s.size() << endl;

}
void main92()
{
	set<int> s;
	set<int, less<int>> s2;
	set<int, greater<int>> s3;//从大到小排序
	for (int i = 0; i < 10; i++)
	{
		s3.insert(rand());
	}
	s3.insert(1000);
	s3.insert(1000);
	s3.insert(1000);
	for (set<int, greater<int>>::iterator it = s3.begin(); it != s3.end(); it++)
	{
		cout << *it << endl;
	}
}
int main()
{
	//main91();
	main92();
	cout << "helloword" << endl;
	system("pause");
	return 0;
}