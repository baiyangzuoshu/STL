#include<iostream>
using namespace std;
#include"map"
#include"string"

void main01()
{
	map<int, string> map1;
	map1.insert(pair<int, string>(1, "maomao1"));
	map1.insert(pair<int, string>(2, "maomao2"));

	map1.insert(make_pair<int, string>(4, "maomao4"));
	map1.insert(make_pair<int, string>(5, "maomao5"));

	map1.insert(map<int, string>::value_type(7, "maomao7"));
	map1.insert(map<int, string>::value_type(8, "maomao8"));

	map1[10] = "maomao10";
	map1[11] = "maomao11";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "ɾ������֮ǰ�ĳ��ȣ�" <<map1.size()<< endl;
	while (!map1.empty())
	{
		map<int, string>::iterator _data = map1.begin();
		cout << _data->first << "\t" << _data->second << endl;
		map1.erase(_data);
	}
	cout << "ɾ������֮��ĳ��ȣ�" << map1.size() << endl;

}

//typedef pair<iterator, bool> _Pairib;
void main02()
{
	map<int, string> map1;
	map1.insert(pair<int, string>(1, "maomao1"));
	map1.insert(pair<int, string>(2, "maomao2"));

	map1.insert(make_pair<int, string>(4, "maomao4"));
	map1.insert(make_pair<int, string>(5, "maomao5"));

	pair<map<int,string>::iterator,bool> mypair=map1.insert(map<int, string>::value_type(7, "maomao7"));
	if (mypair.second)
	{
		cout << "maomao7 ����ɹ�" << endl;
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}
	else
	{
		cout << "key Ϊ7 ����ʧ��" << endl;
	}
	pair<map<int, string>::iterator, bool> mypair2=map1.insert(map<int, string>::value_type(7, "maomao8"));
	if (mypair2.second)
	{
		cout << "maomao8 ����ɹ�" << endl;
		cout << mypair2.first->first << "\t" << mypair2.first->second << endl;
	}
	else
	{
		cout << "key Ϊ7 ����ʧ��" << endl;
	}

	map1[10] = "maomao10";
	map1[10] = "maomao11";//key֮��ͬ��[]���룬���߽��Ḳ��ǰ��

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
}

void main03()
{
	map<int, string> map1;
	map1.insert(pair<int, string>(1, "maomao1"));
	map1.insert(pair<int, string>(2, "maomao2"));

	map1.insert(make_pair<int, string>(4, "maomao4"));
	map1.insert(make_pair<int, string>(5, "maomao5"));

	map1.insert(map<int, string>::value_type(7, "maomao7"));
	map1.insert(map<int, string>::value_type(8, "maomao8"));

	map1[10] = "maomao10";
	map1[11] = "maomao11";

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}

	map<int,string>::iterator myFind = map1.find(100);
	if (myFind == map1.end())
	{
		cout << "û���ҵ�100" << endl;
	}
	else
	{
		cout <<myFind->first<<"\t"<<myFind->second << endl;
	}
	//typedef pair<iterator, iterator> _Pairii;
	pair<map<int,string>::iterator,map<int,string>::iterator>  it =map1.equal_range(8);
	if (it.first == map1.end())
	{
		cout << "û���ҵ����ڵ���8��" << endl;
	}
	else
	{
		cout << it.first->first << "\t" << it.first->second << endl;
	}

	if (it.second == map1.end())
	{
		cout << "û���ҵ�����8��" << endl;
	}
	else
	{
		cout << it.second->first << "\t" << it.second->second << endl;
	}
}
int mainMap()
{
	//main01();
	//main02();
	main03();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}