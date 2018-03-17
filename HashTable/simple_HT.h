
/*
 * ʵ��һ�����׵�hashtable��ֵΪ����int�͡�
 * hash�������ó���ɢ�з�������ѡȡС�ڵ���n���������
 * �ÿ����������ͻ
 */

#ifndef _SIMPLE_HT_H_
#define _SIMPLE_HT_H_

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// hashtable�ڵ�ṹ
struct HT_node
{
	HT_node *next; // �������һ���ڵ�
	int value;     // �ڵ�ֵ
	HT_node(int val) :value(val), next(NULL) {} // �����㹹�캯��
};

// ��ϣ��ṹ
class simple_HT
{
private:
	vector<HT_node*> buckets; // vector�洢����ͷ�ڵ�
	int size;  // hashtable�ڵ���
	int m; // ɢ�к�������

	// ����С�ڵ���N������������������򷵻�-1
	int getPrime(int n); 

public:

	// ���캯������������
	simple_HT(){}

	// ����������������Ŀռ���գ�ָ������
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

	// ��ʼ������
	// ������������ݸ���Ϊbuckets���ٿռ�
	void init();

	// ��������
	// ����hashtable��Ԫ�ظ���
	int Getsize(){
		return size;
	}

	// ��ϣ����
	// ����Ԫ��ֵ������hash��ļ�ֵ
	int hash(const int value);

	// ���Һ���
	// ��hashtable�в���value
	// �ҵ�����true����֮����false
	bool find(const int value);

	// ���뺯��
	// ��ֵvalue���뵽hashtable��
	int insert(int value);

	// ɾ������
	// ��hashtable��ɾȥֵ����value�Ľڵ�
	void erase(int value);

	// ��������洢��ʽ��ӡ��������
	void printHT();
};

#endif