#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"vector"
#define MAOLOG cout<<"["<<__FILE__<<":"<<__LINE__<<"]"
class Person
{
public:
	Person(char *name,int age)
	{
		m_name = new char[strlen(name)+1];
		strcpy(m_name,name);
		m_age = age;
	}

	Person(const Person& obj)
	{
		MAOLOG << "obj.m_name len:" << strlen(obj.m_name) << endl;
		//MAOLOG << "len:" << strlen(m_name) << endl;
		m_name = new char[strlen(obj.m_name)+1];
		MAOLOG << "len:" << strlen(m_name) << endl;
		strcpy(m_name, obj.m_name);
		m_age = obj.m_age;
	}

	Person& operator=(const Person& obj)
	{
		if (this->m_name)
		{
			if (m_name)
			{
				delete[] m_name;
				m_name = nullptr;
				m_age = 0;
			}
		}
		//
		m_name = new char[strlen(obj.m_name) + 1];
		strcpy(m_name, obj.m_name);
		m_age = obj.m_age;
		return *this;
	}

	~Person()
	{
		if (m_name!=nullptr)
		{
			delete[] m_name;
			m_name = nullptr;
			m_age = 0;
		}
	}
	
public:
	int		m_age;
	char	*m_name;
};

void main1301()
{
	Person p1("p1", 34);

	vector<Person*> v1;
	v1.push_back(&p1);
	MAOLOG << "hellowrold" << endl;
}
int main()
{
	//当进行到栈pop此函数时，因为stl容器是值拷贝，于是我们在析构函数将会遇到野指针，
	//进而会奔溃，因此我们需要重写Person默认拷贝函数，已经默认=函数
	main1301();
	system("pause");
	return 0;
}