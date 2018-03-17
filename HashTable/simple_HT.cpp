
#include "simple_HT.h"

int simple_HT::getPrime(int n)
{
	int i = n;
	for (; i > 1; i--)
	{
		bool isprime = false;

		// 对于值i，使其与2~sqrt(i)相除，若i为质数则均不能整除，若不为质数则存在能整除的值
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
	return (i != 1) ? i : -1; // 如果n以内没有质数则返回-1
}

void simple_HT::init()
{
	cout << "please input data count: ";
	cin >> this->size; // 输入哈希表存储数据量

	// 对链表进行初始化，头结点存入其对应的余数
	for (int i = 0; i < Getsize(); i++)
	{
		HT_node *tmp = new HT_node(i);
		buckets.push_back(tmp);
	}
	cout << "hash函数的除数是：" << getPrime(Getsize()) << endl;
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
	HT_node *head = buckets[key]->next; // 每个开链链表的头结点存储的是hash之后的余数，所以这里head要指向next才能正确查找
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

	// 尾插法将value插入到相应链表尾
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
	//将所有有数据存储的链表打印出来
	for (int i = 0; i < Getsize(); i++) 
	{
		HT_node *tmp = buckets[i];
		if (tmp->next != NULL) // 只打印有数据存储的链表
		{
			cout << "链表" << i << "：";
			tmp = tmp->next; // 去除头结点除数的干扰
			while (tmp != NULL)
			{
				cout << tmp->value << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
	}
}
