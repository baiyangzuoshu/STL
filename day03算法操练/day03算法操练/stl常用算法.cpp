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

int showElem1(const int& n)
{
	return 100 + n;
}

void for_each_PK_transform()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(7);
	v1.push_back(-1);
	for_each(v1.begin(), v1.end(), showElem);
	/*
	template<class _InIt,
	class _OutIt,
	class _Fn1> inline
	_OutIt _Transform(_InIt _First, _InIt _Last,
	_OutIt _Dest, _Fn1 _Func)
	{	// transform [_First, _Last) with _Func
	for (; _First != _Last; ++_First, (void)++_Dest)
	*_Dest = _Func(*_First);
	return (_Dest);
	}
	*/
	transform(v1.begin(), v1.end(), v1.begin(), showElem1);
}

void adjacent_findMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(7);
	v1.push_back(1);

	vector<int>::iterator it=adjacent_find(v1.begin(), v1.end());
	if (it==v1.end())
	{
		cout << "no found";
	}
	else
	{
		cout << *it << endl;
	}

	int m_distance = distance(v1.begin(), it);
	cout << "distance:" << m_distance << endl;
}
//二分法查找
void binary_searchMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	bool isFound = binary_search(v1.begin(), v1.end(), 5);
	if (isFound)
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "no found" << endl;
	}
}

void countMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(9);

	int m_count = count(v1.begin(), v1.end(), 5);
	cout << m_count << endl;
}

bool GreatCount(const int& n)
{
	if (n > 3)
	{
		return true;
	}
	return false;
}
void countIfMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(9);

	int m_count = count_if(v1.begin(), v1.end(), GreatCount);
	cout << m_count << endl;
}

void mergeMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int> v3;
	v3.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	printT(v3);
}

class Student
{
public:
	Student(int m_age, string strName)
	{
		this->age = m_age;
		this->name = strName;
	}
	void printInfo()
	{
		cout << this->age << "," << this->name << endl;
	}
	int getAge()
	{
		return age;
	}
private:
	int age;
	string name;
};
bool sortBool(Student* s1, Student* s2)
{
	return s1->getAge() > s2->getAge();
}

void sortMain()
{
	Student s(10, "s");
	Student s3(9, "s3");
	Student s4(50, "s4");
	Student s2(30, "s2");

	vector<Student*> v1;
	v1.push_back(&s);
	v1.push_back(&s3);
	v1.push_back(&s4);
	v1.push_back(&s2);

	for (auto it:v1)
	{
		it->printInfo();
	}

	sort(v1.begin(), v1.end(), sortBool);
	cout << "sort........." << endl;
	for (auto it : v1)
	{
		it->printInfo();
	}
}

void copyMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int> v2;
	v2.resize(v1.size());

	copy(v1.begin(), v1.end(), v2.begin());
	printT(v2);
}
void replaceMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	printT(v1);
	replace(v1.begin(), v1.end(), 3,9);
	printT(v1);
}

bool  Greate_5(const int& n)
{
	if (n > 5)
		return true;
	return false;
}
void replaceIfMain()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	printT(v1);
	replace_if(v1.begin(), v1.end(), Greate_5, 9);
	printT(v1);
}
int main()
{
	//foreachMain();
	//transformMain();
	//for_each_PK_transform();
	//adjacent_findMain();
	//binary_searchMain();
	//countMain();
	//countIfMain();
	//mergeMain();
	//sortMain();
	//copyMain();
	//replaceMain();
	replaceIfMain();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}