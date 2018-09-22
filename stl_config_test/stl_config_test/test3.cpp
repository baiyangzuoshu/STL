#include<cstdlib>
#include<iostream>
using namespace std;

int	fcmp(const void* elem1,const void* elem2);

void	main()
{
	int	ia[10] = {25,63,9,85,2,3,57,4};
	for (int i = 0; i < 10; i++)
	{
		cout << "i:" << i << ",value:" << ia[i] << endl;
	}

	qsort(ia, sizeof(ia) / sizeof(int), sizeof(int), fcmp);
	
	for (int i = 0; i < 10; i++)
	{
		cout << "i:" << i << ",value:" << ia[i] << endl;
	}

	system("pause");
}

int	fcmp(const void* elem1, const void* elem2)
{
	const int* i1 = (const int*)elem1;
	const int* i2 = (const int*)elem2;

	if (*i1<*i2)
	{
		return -1;
	}
	else if (*i1==*i2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}