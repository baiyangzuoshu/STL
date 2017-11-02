#include<iostream>
using namespace std;

#include"string"
#include<vector>
#include<list>
#include"set "
#include<functional>
#include<algorithm>
//plus¡∑œ∞
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
int main()
{
	main21();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}