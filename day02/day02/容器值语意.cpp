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
	//�����е�ջpop�˺���ʱ����Ϊstl������ֵ��������������������������������Ұָ�룬
	//�����ᱼ�������������Ҫ��дPersonĬ�Ͽ����������Ѿ�Ĭ��=����
	main1301();
	system("pause");
	return 0;
}