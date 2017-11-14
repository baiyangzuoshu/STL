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
		tmp.name = "ѡ��";
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
		//���
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
		//�������
		if (0 == tmpCount % 6)
		{
			cout << "С��ɼ�" << endl;
			for (multimap<int, int>::iterator it = multimapGroup.begin(); it != multimapGroup.end();it++)
			{
				//��� ���� �÷�
				cout << it->second << "\t" << m_mSpeaker[it->second]->name <<"\t"<< it->first << endl;
			}
			//ǰ��
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
	printf("��%d�ֲ�������\n",1+index);
	for (vector<int>::iterator it = v.begin(); it != v.end();it++)
	{
		cout << "�������:" << *it << "\t" << m_mSpeaker[*it]->m_score[index] << "\t" << m_mSpeaker[*it]->name << endl;
	}
	return 0;
}
int main()
{
	//���������
	map<int, Speaker*>	m_mSpeaker;//�μӱ�����ѡ��
	vector<int>			v1;//��һ���ݽ�������ѡ��
	vector<int>			v2;//�ڶ����ݽ�������ѡ��
	vector<int>			v3;//�������ݽ�������ѡ��
	vector<int>			v4;//ǰ�����ݽ���ѡ��

	//����ѡ�� �õ���һ��ѡ�ֵĲ�������
	GenSpeaker(m_mSpeaker, v1);
	//��һ�� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴����
	cout << "�������ʼ��һ�ֱ���" << endl;
	//cin.get();
	speech_contest_draw(v1);
	speech_contest(0, v1, m_mSpeaker,v2);
	speech_contest_print(0, v2,m_mSpeaker);
	//�ڶ��� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴����
	cout << "�������ʼ�ڶ��ֱ���" << endl;
	//cin.get();
	speech_contest_draw(v2);
	speech_contest(1, v2, m_mSpeaker, v3);
	speech_contest_print(0, v3, m_mSpeaker);
	//������ ѡ�ֳ�ǩ ѡ�ֱ��� �鿴����
	cout << "�������ʼ�����ֱ���" << endl;
	//cin.get();
	speech_contest_draw(v3);
	speech_contest(2, v3, m_mSpeaker, v4);
	speech_contest_print(0, v4, m_mSpeaker);
	
	cout << "hellowrold" << endl;
	system("pause");
	return 0;
}