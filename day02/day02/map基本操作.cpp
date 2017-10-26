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
	cout << "删除操作之前的长度：" <<map1.size()<< endl;
	while (!map1.empty())
	{
		map<int, string>::iterator _data = map1.begin();
		cout << _data->first << "\t" << _data->second << endl;
		map1.erase(_data);
	}
	cout << "删除操作之后的长度：" << map1.size() << endl;

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
		cout << "maomao7 插入成功" << endl;
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}
	else
	{
		cout << "key 为7 插入失败" << endl;
	}
	pair<map<int, string>::iterator, bool> mypair2=map1.insert(map<int, string>::value_type(7, "maomao8"));
	if (mypair2.second)
	{
		cout << "maomao8 插入成功" << endl;
		cout << mypair2.first->first << "\t" << mypair2.first->second << endl;
	}
	else
	{
		cout << "key 为7 插入失败" << endl;
	}

	map1[10] = "maomao10";
	map1[10] = "maomao11";//key之相同，[]插入，后者将会覆盖前者

	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
}
int main()
{
	//main01();
	main02();
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}