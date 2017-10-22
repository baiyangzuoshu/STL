#include<iostream>
using namespace std;
#include<queue>
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

void main61()
{
	Teacher t1, t2, t3;
	t1.age = 9;
	t2.age = 19;
	t3.age = 39;

	queue<Teacher*> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);

	while (!q.empty())
	{
		Teacher* tmp = q.back();//访问最后一个进入queue的数据
		tmp->printTeacherInfo();
		q.pop();
	}
	cout << "size:"<<q.size() << endl;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);

	while (!q.empty())
	{
		Teacher* tmp = q.front();
		tmp->printTeacherInfo();
		q.pop();
	}
}
int mainqueue()
{
	main61();
	cout << "helloword" << endl;
	system("pause");
	return 0;
}