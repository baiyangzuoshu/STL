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
	cout << t << " ";
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

template<typename T>
class SumAdd
{
public:
	T operator()(T& t1, T& t2)
	{
		return t1 + t2;
	}
};

//二元函数对象和二元谓词
void main04()
{
	vector<int> v1, v2,v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);


	v2.push_back(5);
	v2.push_back(53);
	v2.push_back(54);
	//v2.push_back(58);思考，这样可以吗？v1.push_back(58);可以吗？

	v3.resize(10);
	
	/*
	template<class _InIt1,
	class _InIt2,
	class _OutIt,
	class _Fn2> inline
	_OutIt transform(_InIt1 _First1, _InIt1 _Last1,
	_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	// transform [_First1, _Last1) and [_First2, ...) with _Func
	_DEBUG_RANGE_PTR(_First1, _Last1, _First2);
	_DEBUG_POINTER_IF(_First1 != _Last1, _Dest);
	_DEBUG_POINTER_IF(_First1 != _Last1, _Func);
	return (_Transform2(_Unchecked(_First1), _Unchecked(_Last1),
	_First2, _Dest, _Func,
	_Is_checked(_Dest)));
	}
	*/
	transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),SumAdd<int>());

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
}

bool myCompare(const int& value1, const int& value2)
{
	return value1 < value2;
}

//二元谓词
void main05()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++)
	{
		int _value = rand() % 100;
		v1[i] = _value;
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	sort(v1.begin(),v1.end(),myCompare);

	for_each(v1.begin(), v1.end(), ShowFunction2);
}

struct CompareNoCare
{
	bool operator()(const string& str1, const string& str2)
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(), str1.end(), str1_.begin(), toupper);

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), toupper);

		return str1_ < str2_;
	}
};

void main06()
{
	set<string> s1;
	s1.insert("dfsd");
	s1.insert("dffff");
	s1.insert("dllll");
	s1.insert("dPoP");

	set<string>::iterator it = s1.find("dpop");//默认不区分大小写
	if (it == s1.end())
	{
		cout << "no found dpop" << endl;
	}
	else
	{
		cout << "found dpop" << endl;
	}
	//二元谓词
	set<string, CompareNoCare> s2;
	s2.insert("dfsd");
	s2.insert("dffff");
	s2.insert("dllll");
	s2.insert("dPoP");

	set<string, CompareNoCare>::iterator it2 = s2.find("dpop");//默认不区分大小写
	if (it2 == s2.end())
	{
		cout << "no found dpop" << endl;
	}
	else
	{
		cout << "found dpop" << endl;
	}
}
int mainFunction()
{
	//main01();
	//main02();
	//main03();
	//main04();
	//main05();
	//main06();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}