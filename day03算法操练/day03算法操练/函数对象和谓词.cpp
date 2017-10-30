#include<iostream>
using namespace std;

#include"string"
#include<vector>
#include<list>
#include"set "
#include<functional>
#include<algorithm>

//函数对象，类重载了()
template <typename T>
class ShowElemt
{
public:
	ShowElemt()
	{
		n = 0;
	}
	void operator()(T& t)
	{
		n++;
		cout << t<< endl;
	}
	
	void printN()
	{
		cout <<"n:"<<n << endl;
	}
private:
	int n;
};

//类模板函数
template <typename T>
void ShowFunction1(T& t)
{
	cout << t << endl;
}

void ShowFunction2(int t)
{
	cout << t << endl;
}
//普通函数和函数对象的异同
void main01()
{
	int a = 10;
	ShowElemt<int> showElemt;
	showElemt(a);//函数对象()的调用，很像一个函数//仿函数

	ShowFunction1<int>(a);
	ShowFunction2(a);
}
//函数对象是类对象，能保存调用状态信息，突破函数的概念
void main02()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(9);

	for_each(v.begin(),v.end(),ShowElemt<int>());
	cout << endl;
	for_each(v.begin(),v.end(),ShowFunction2);
	cout << endl;

	ShowElemt<int> showElemt;
	//for_each算法，函数对象传递，是值传递
	showElemt=for_each(v.begin(), v.end(), showElemt);
	showElemt.printN();
}
template<typename T>
class IsDiv
{
public:
	IsDiv(const T& divisor)
	{
		this->divisor = divisor;
	}

	bool operator()(T& t)
	{
		return (t%divisor == 0);
	}
private:
	T divisor;
};
void main03()
{
	vector<int> v;
	for (int i = 1; i < 33; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator it;
	/*
	template<class _InIt,
	class _Pr> inline
	_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	_DEBUG_RANGE_PTR(_First, _Last, _Pred);
	return (_Rechecked(_First,
	_Find_if(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}
	*/
	//在stl中，我们应该分清楚算法返回值，是迭代器还是函数对象
	it = find_if(v.begin(),v.end(),IsDiv<int>(4));
	if (it == v.end())
	{
		cout << "no found"<< endl;
	}
	else
	{
		cout << "it:" << *it << endl;
	}
}
int main()
{
	//main01();
	//main02();
	main03();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}