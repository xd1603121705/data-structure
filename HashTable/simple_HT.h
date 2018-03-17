
/*
 * 实现一个简易的hashtable，值为整数int型。
 * hash函数采用除法散列法，除数选取小于等于n的最大质数
 * 用开链法解决冲突
 */

#ifndef _SIMPLE_HT_H_
#define _SIMPLE_HT_H_

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// hashtable节点结构
struct HT_node
{
	HT_node *next; // 链表的下一个节点
	int value;     // 节点值
	HT_node(int val) :value(val), next(NULL) {} // 链表结点构造函数
};

// 哈希表结构
class simple_HT
{
private:
	vector<HT_node*> buckets; // vector存储链表头节点
	int size;  // hashtable节点数
	int m; // 散列函数除数

	// 返回小于等于N的最大素数，不存在则返回-1
	int getPrime(int n); 

public:

	// 构造函数和析构函数
	simple_HT(){}

	// 析构函数，将申请的空间回收，指针销毁
	~simple_HT()
	{
		for (int i = 0; i < buckets.size(); i++)
		{
			if (buckets[i] == NULL)
				continue;
			HT_node *p, *q = buckets[i];
			buckets[i] = NULL;
			while (q)
			{
				p = q->next;
				delete q;
				q = p;
			}
		}
	}

	// 初始化函数
	// 根据输入的数据个数为buckets开辟空间
	void init();

	// 计数函数
	// 返回hashtable的元素个数
	int Getsize(){
		return size;
	}

	// 哈希函数
	// 输入元素值，返回hash后的键值
	int hash(const int value);

	// 查找函数
	// 在hashtable中查找value
	// 找到返回true，反之返回false
	bool find(const int value);

	// 插入函数
	// 将值value插入到hashtable中
	int insert(int value);

	// 删除操作
	// 从hashtable中删去值等于value的节点
	void erase(int value);

	// 按照链表存储格式打印所有数据
	void printHT();
};

#endif