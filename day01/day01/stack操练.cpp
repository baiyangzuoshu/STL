#include<iostream>
using namespace std;
#include"stack"

void main51()
{
	stack<int> s;

	for (int i = 0; i < 10; i++)
	{
		s.push(i+100);
	}

	cout << "size:" << s.size() << endl;

	while (!s.empty())
	{
		int data = s.top();
		cout << data << " ";
		s.pop();
	}
}

class Teacher
{
public:
	int age;
	char  name[32];
	void printTeacherInfo()
	{
		cout << " age:" << age;
	}
};

void main52()
{
	Teacher t1, t2, t3;
	t1.age = 32;
	t2.age = 34;
	t3.age = 36;

	stack<Teacher*> s;
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	while (!s.empty())
	{
		Teacher* t = s.top();
		t->printTeacherInfo();
		s.pop();
	}

}
int mainStack()
{
	//main51();
	main52();
	cout << "helloword" << endl;
	system("pause");
	return 0;
}