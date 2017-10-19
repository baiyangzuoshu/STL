#include<iostream>
#include"string"
using namespace std;
void main21()
{
	string s1 = "aaaa";
	string s2("bbbb");
	string s3 = s1;
	string s4(10, 'a');

	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	cout << "s3:" << s3 << endl;
	cout << "s4:" << s4 << endl;
}

void main22()
{
	string s = "gdddsgddgg";

	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i]<< endl;
	}
	cout << "_________________________________________" << endl;
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << (*it) << endl;
	}
	cout << "_________________________________________" << endl;
	try
	{
		for (int i = 0; i < s.length()+3; i++)
		{
			cout << s.at(i) << endl;
		}
	}
	catch(...)
	{
		cout << "发生异常"<< endl;
	}
	cout << "_________________________________________" << endl;
	try
	{
		for (int i = 0; i < s.length() + 3; i++)
		{
			cout << s[i] << endl;//出现错误，不向外面抛出异常，直接终端中断
		}
	}
	catch (...)
	{
		cout << "发生异常" << endl;
	}
}

void main23()
{
	string s = "gddgdhfhsd";
	printf("s:%s\n",s.c_str());

	char buf[128] = { 0 };
	s._Copy_s(buf,128, 3, 0);
	cout << "buf:" << buf << endl;
}

void main24()
{
	string s1 = "aaaa";
	string s2 = "bbbb";
	string s3 = s1 + s2;
	cout <<"s1+s2:"<<s3 << endl;

	string s4 = s1.append(s2);
	cout << "s1.append(s2):" << s4 << endl;
}

void main25()
{
	string s = "mao live mao like mao";

	int pos = s.find("mao",0);
	cout << "pos:" << pos << endl;

	int count = 0;
	int offect = s.find("mao",0);
	while (offect != -1)
	{
		count++;
		offect = offect + 1;
		offect = s.find("mao", offect);
	}
	cout << "count:" << count << endl;
	//replace()
	cout << "replace replace replace replacere place re placereplacereplacereplacereplace" << endl;
	string s1 = "aaa bbb ccc";
	s1.replace(3, 3, "AAA");
	cout << "s1:" << s1 << endl;

	offect = s.find("mao", 0);
	while (offect != string::npos)
	{
		s.replace(offect, 3, "JIA");
		offect = offect + 1;
		offect = s.find("mao", offect);
	}
	cout << "s:" << s << endl;
}
int main()
{
	//main21();
	//main22();
	//main23();
	//main24();
	main25();
	cout << "helloworld" << endl;
	system("pause");
	return 0;
}
