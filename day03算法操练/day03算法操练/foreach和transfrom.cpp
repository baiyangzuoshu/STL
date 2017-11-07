#include<iostream>
using namespace std;
#include"string"
#include<vector>
#include<list>
#include"set "
#include<functional>
#include<algorithm>

void printT(vector<int>& t)
{
	for (auto it:t)
	{
		cout << it<<" ";
	}
	cout << endl;
}

void printList(list<int>& t)
{
	for (auto it : t)
	{
		cout << it << " ";
	}
	cout << endl;
}

void showElem(int& n)
{
	cout << n << " ";
}

class CMyShow
{
public:
	CMyShow()
	{
		num = 0;
	}
	void printNum()
	{
		cout << "num:" << num << endl;
	}
	void operator()(const int& n)
	{
		num++;
		cout << n << " ";
	}
private:
	int num;
};
void foreachMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(7);
	v1.push_back(-1);
	printT(v1);
	//回调函数
	for_each(v1.begin(), v1.end(), showElem);
	cout << endl;
	/*
	template<class _InIt,
	class _Fn1> inline
	_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
	{	// perform function for each element
	_DEBUG_RANGE_PTR(_First, _Last, _Func);
	_For_each(_Unchecked(_First), _Unchecked(_Last), _Func);

	return (_STD move(_Func));
	}
	*/
	CMyShow myFunc;
	CMyShow myShow=for_each(v1.begin(), v1.end(), myFunc);
	myFunc.printNum();//myShow，myFunc不是同一个对象
	myShow.printNum();
}

int increase(const int& n)
{
	return 100 + n;
}
void transformMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(7);
	v1.push_back(-1);
	printT(v1);
	//回调函数
	transform(v1.begin(),v1.end(),v1.begin(),increase);
	printT(v1);
	//预定义函数对象
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	printT(v1);

	//函数适配器
	list<int> myList;
	myList.resize(v1.size());

	transform(v1.begin(), v1.end(), myList.begin(), bind2nd(multiplies<int>(),10));
	printList(myList);
}
int main()
{
	//foreachMain();
	transformMain();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}