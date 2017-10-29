#include<iostream>
using namespace std;
#include"map"
#include"string"
#define MAOLOG cout<<"["<<__FILE__<<":"<<__LINE__<<"]"
class Person
{
public:
	Person()
	{

	}
public:
	int age;
	string name;
};

void main1201()
{
	multimap<string, Person*> map1;

	Person p1, p2, p3, p4, p5;
	p1.age = 31;
	p1.name = "张1";
	p2.age = 32;
	p2.name = "张2";

	p3.age = 33;
	p3.name = "王1";
	p4.age = 34;
	p4.name = "王2";

	p5.age = 35;
	p5.name = "李1";

	map1.insert(pair<string, Person*>("salary", &p1));
	map1.insert(pair<string, Person*>("salary", &p2));
	map1.insert(pair<string, Person*>("HR", &p3));
	map1.insert(pair<string, Person*>("HR", &p4));
	map1.insert(pair<string, Person*>("Engineer", &p5));

	for (multimap<string, Person*>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		MAOLOG << it->first << "\t" << it->second->name << endl;
	}
	MAOLOG << "遍历结束" << endl;

	int HRNumber = map1.count("HR");
	MAOLOG << "HRNumber:" << HRNumber << endl;

	int tag = 0;
	multimap<string, Person*>::iterator it = map1.find("HR");
	MAOLOG << "enter HR" << endl;
	while (it != map1.end() && tag < HRNumber)
	{
		MAOLOG << it->first << "\t" << it->second->name << endl;
		it++;
		tag++;
	}
}

int mainMutilmap()
{
	main1201();
	system("pause");
	return 0;
}