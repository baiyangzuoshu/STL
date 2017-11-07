#include<iostream>
using namespace std;

#include"string"
#include<vector>
#include<list>
#include"set "
#include<functional>
#include<algorithm>
//plus练习,预定义函数对象
void main21()
{
	/*
	template<class _Ty = void>
	struct plus
	{	// functor for operator+
	typedef _Ty first_argument_type;
	typedef _Ty second_argument_type;
	typedef _Ty result_type;

	_CONST_FUN _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator+ to operands
	return (_Left + _Right);
	}
	};
	*/
	plus<int> intAdd;
	int a = 10;
	int b = 20;
	int c = intAdd(a, b);
	cout << "c:" << c << endl;

	plus<string> stringAdd;
	string x = "aaa";
	string y = "bbbb";
	string z = stringAdd(x, y);
	cout << "z:" << z << endl;
}

class isGreat
{
public:
	isGreat(int num)
	{
		m_num = num;
	}
	bool operator()(const int& num)
	{
		if (num > m_num)
			return true;
		return false;
	}
private:
	int m_num;
};
//函数适配器
void main22()
{
	vector<int> v1;
	for (int i = 0; i < 10;i++)
	{
		v1.push_back(i + 1);
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	int num = count(v1.begin(), v1.end(), 3);
	cout << "=3 num:" << num << endl;
	//使用谓词
	int num1 = count_if(v1.begin(),v1.end(),isGreat(2));
	cout << ">2 num1:" << num1 << endl;
	//使用预定义函数对象
	/*
	template<class _Ty = void>
	struct greater
	{	// functor for operator>
	typedef _Ty first_argument_type;
	typedef _Ty second_argument_type;
	typedef bool result_type;

	_CONST_FUN bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator> to operands
		return (_Left > _Right);
		}
	};
	*/
	int num3 = count_if(v1.begin(),v1.end(),bind2nd(greater<int>(),2));
	cout << ">2 num3:" << num3 << endl;
	//求奇数的个数
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "奇数的个数：:" << num4 << endl;
	//求偶数的个数,not1函数适配器的作用是取反
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "求偶数的个数：:" << num5 << endl;
}
int main03()
{
	//main21();
	main22();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}