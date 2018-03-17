
#include "simple_HT.h"

int main()
{
	simple_HT HT;

	HT.init();

	int n = HT.Getsize();
	cout << "please input " << n << " datas" << endl;

	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		if (HT.insert(data) == -1) // 输入重复则计数值i--
			i--;
	}

	HT.printHT();

	int test;
	while (1)
	{
		cout << "please input data needed to find: ";
		cin >> test;
		cout << HT.find(test) << endl;
	}

	return 0;
}