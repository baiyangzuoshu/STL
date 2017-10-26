#include<iostream>
using namespace std;
#include"set"
#include"functional"
#pragma warning(disable:4996)

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

class Student
{
public:
	Student(int age, char* name)
	{
		this->age = age;
		strcpy(this->name, name);
	}
	void printStudent()
	{
		cout << "age:" << age << ",name:" << name;
	}
	int getAge()
	{
		return age;
	}
public:
	int		age;
	char	name[32];
};

struct Functionor
{
	bool operator()(const Student& left, const Student& right)
	{
		if (left.age > right.age)//大到小排序
			return true;
		return false;
	}
};

void main93()
{
	Student s1(1, "s1");
	Student s2(10, "s2");
	Student s3(8, "s3");
	Student s4(16,"s4");

	set<Student, Functionor> s;
	s.insert(s1);
	s.insert(s2);
	s.insert(s3);
	s.insert(s4);

	for (set<Student, Functionor>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "age:" << (*it).age << ",name:" << (*it).name << endl;
	}
}

void main94()
{
	Student s1(1, "s1");
	Student s2(10, "s2");
	Student s3(8, "s3");
	Student s4(16, "s4");
	Student s5(10, "s5");

	set<Student, Functionor> s;
	auto it=s.insert(s2);
	if (true == it.second)
	{
		cout << "success";
	}
	else
	{
		cout << "faile";
	}
	s.insert(s4);
	auto it2=s.insert(s5);
	if (true == it2.second)
	{
		cout << "success";
	}
	else
	{
		cout << "faile";
	}
	for (set<Student, Functionor>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "age:" << (*it).age << ",name:" << (*it).name << endl;
	}
}

void main95()
{
	set<int> s;
	for (int i = 0; i < 10; i++)
	{
		s.insert(i);
	}
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "size" << s.size() << endl;
	set<int>::iterator it0 = s.find(5);
	cout << "it0:" << *it0 << endl;
	set<int>::iterator it1 = s.lower_bound(5);
	cout << "it1:" << *it1 << endl;
	set<int>::iterator it2 = s.upper_bound(5);
	cout << "it2:" << *it2 << endl;

	pair<set<int>::iterator, set<int>::iterator> it3 = s.equal_range(5);
	set<int>::iterator it4 = it3.first;
	set<int>::iterator it5 = it3.second;
	cout << "it4:" << *it4 << endl;
	cout << "it5:" << *it5 << endl;
}
int main()
{
	//main91();
	//main92();
	//main93();
	//main94();
	main95();
	cout << "helloword" << endl;
	system("pause");
	return 0;
}