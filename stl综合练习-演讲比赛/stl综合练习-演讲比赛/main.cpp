#include<iostream>
using namespace std;
#include"string"
#include<vector>
#include<list>
#include<numeric>
#include"set "
#include<functional>
#include<algorithm>
#include"map"
#include"deque"

class Speaker
{
public:
	string name;
	int    m_score[3];
};

int GenSpeaker(map<int, Speaker*>& m_mSpeaker, vector<int>& v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());

	for (int i = 0; i < 24;i++)
	{
		Speaker tmp;
		tmp.name = "选手";
		tmp.name = tmp.name + str[i];
		m_mSpeaker.insert(pair<int,Speaker*>(i+100,&tmp));
	}

	for (int i = 0; i < 24;i++)
	{
		v.push_back(100 + i);
	}
	return 0;
}

int speech_contest_draw(vector<int>& v)
{
	random_shuffle(v.begin(), v.end());
	return 0;
}

int speech_contest(int index, vector<int>& v1, map<int, Speaker*>& m_mSpeaker, vector<int>& v2)
{
	int tmpCount = 0;
	multimap<int, int, greater<int>> multimapGroup;
	for (vector<int>::iterator it = v1.begin(); it != v1.end();it++)
	{
		//打分
		{
			/*
			deque<int> dscore;
			for (int j = 0; j < 10;j++)
			{
			int score = 50 + rand() % 50;
			dscore.push_back(score);
			}

			sort(dscore.begin(),dscore.end());
			dscore.pop_back();
			dscore.pop_front();
			*/

			int scoresum = 800;//accumulate(dscore.begin(),dscore.end(),0);
			int scoreavg = scoresum / 8;
			m_mSpeaker[*it]->m_score[index] = scoreavg;
			multimapGroup.insert(pair<int, int>(scoreavg, *it));
		}
		//处理分组
		if (0 == tmpCount % 6)
		{
			cout << "小组成绩" << endl;
			for (multimap<int, int>::iterator it = multimapGroup.begin(); it != multimapGroup.end();it++)
			{
				//编号 姓名 得分
				cout << it->second << "\t" << m_mSpeaker[it->second]->name <<"\t"<< it->first << endl;
			}
			//前三
			while (multimapGroup.size()>3)
			{
				multimap<int, int>::iterator it = multimapGroup.begin();
				v2.push_back(it->second);
				multimapGroup.erase(it);
			}
			multimapGroup.clear();
		}
	}
	return 0;
}

int speech_contest_print(int index, vector<int>& v, map<int, Speaker*>& m_mSpeaker)
{
	printf("第%d轮参赛名单\n",1+index);
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "参赛编号:" << *it << "\t" << m_mSpeaker[*it]->m_score[index] << "\t" << m_mSpeaker[*it]->name << endl;
	}
	return 0;
}
int main()
{
	//容器的设计
	map<int, Speaker*>	m_mSpeaker;//参加比赛的选手
	vector<int>			v1;//第一轮演讲比赛的选手
	vector<int>			v2;//第二轮演讲比赛的选手
	vector<int>			v3;//第三轮演讲比赛的选手
	vector<int>			v4;//前三名演讲的选手

	//产生选手 得到第一轮选手的参赛名单
	GenSpeaker(m_mSpeaker, v1);
	//第一轮 选手抽签 选手比赛 查看比赛
	cout << "任意键开始第一轮比赛" << endl;
	//cin.get();
	speech_contest_draw(v1);
	speech_contest(0, v1, m_mSpeaker,v2);
	speech_contest_print(0, v2,m_mSpeaker);
	//第二轮 选手抽签 选手比赛 查看比赛
	cout << "任意键开始第二轮比赛" << endl;
	//cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, m_mSpeaker, v3);
	speech_contest_print(0, v3, m_mSpeaker);
	//第三轮 选手抽签 选手比赛 查看比赛
	cout << "任意键开始第三轮比赛" << endl;
	//cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, m_mSpeaker, v4);
	speech_contest_print(0, v4, m_mSpeaker);
	
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}