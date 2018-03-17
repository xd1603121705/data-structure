
#include "simple_HT.h"

int simple_HT::getPrime(int n)
{
	int i = n;
	for (; i > 1; i--)
	{
		bool isprime = false;

		// ����ֵi��ʹ����2~sqrt(i)�������iΪ���������������������Ϊ�����������������ֵ
		for (int j = 2; j <= (int)sqrt(i); j++)
		{
			if (i % j == 0){
				isprime = true;
				break;
			}
		}
		if (!isprime)
			break;
	}
	return (i != 1) ? i : -1; // ���n����û�������򷵻�-1
}

void simple_HT::init()
{
	cout << "please input data count: ";
	cin >> this->size; // �����ϣ��洢������

	// ��������г�ʼ����ͷ���������Ӧ������
	for (int i = 0; i < Getsize(); i++)
	{
		HT_node *tmp = new HT_node(i);
		buckets.push_back(tmp);
	}
	cout << "hash�����ĳ����ǣ�" << getPrime(Getsize()) << endl;
}

int simple_HT::hash(int value)
{
	int m = getPrime(Getsize());
	//cout << "m = " << m << endl;
	return value % m;
}

bool simple_HT::find(int value)
{
	int key = hash(value);
	HT_node *head = buckets[key]->next; // ÿ�����������ͷ���洢����hash֮�����������������headҪָ��next������ȷ����
	while (head)
	{
		if (head->value == value)
			return true;
		head = head->next;
	}
	return false;
}

int simple_HT::insert(int value)
{
	if (find(value))
	{
		cout << "this value have already been inserted, please input again" << endl;
		return -1;
	}
	int key = hash(value);
	HT_node *tmp = new HT_node(value); 

	// β�巨��value���뵽��Ӧ����β
	HT_node *head = buckets[key];
	while (head->next)
		head = head->next;
	head->next = tmp;
	return 0;
}

void simple_HT::erase(int value)
{
	if (!find(value))
		return;
	int key = hash(value);
	HT_node *curr = buckets[key];
	if (curr->value == value)
	{
		buckets[key] = NULL;
		delete curr;
		curr = NULL;
	}
	else
	{
		HT_node *prev = curr;
		curr = curr->next;
		while (curr)
		{
			if (curr->value == value)
			{
				prev->next = curr->next;
				delete curr;
				curr = NULL;
			}
			prev = curr;
			curr = curr->next;
		}
	}
}

void simple_HT::printHT()
{
	//�����������ݴ洢�������ӡ����
	for (int i = 0; i < Getsize(); i++) 
	{
		HT_node *tmp = buckets[i];
		if (tmp->next != NULL) // ֻ��ӡ�����ݴ洢������
		{
			cout << "����" << i << "��";
			tmp = tmp->next; // ȥ��ͷ�������ĸ���
			while (tmp != NULL)
			{
				cout << tmp->value << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
	}
}
