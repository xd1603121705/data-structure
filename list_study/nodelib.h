#ifndef INCLUDE_NODELIB_H
#define INCLUDE_NODELIB_H

#include "node.h"

// ���ɽ��
template <class T>
Node< T > * GetNode(const T& item, Node< T > * nextPtr = NULL)
{
	Node< T > * newNode;
	newNode = new Node< T >(item, nextPtr);
	if (newNode == NULL)
	{
		cerr << "Memory allocation failure!" << endl;
		exit(1);
	}
	return newNode;
}

// �����㣨ͷ�巨,head��Ϊͷ��㣩
template <class T>
void InsertFront(Node< T > * & head, T item)
{
	head = GetNode(item, head);
}

// �����㣨β�巨��
template <class T>
void InsertRear(Node< T > * & head, T item)
{
	Node< T > * currPtr = head;
	if (currPtr == NULL)
		InsertFront(head, item);
	else
	{
		while (currPtr->NextNode() != NULL)
			currPtr = currPtr->NextNode();
		Node< T > * newNode;
		newNode = new Node< T >(item);
		currPtr->InsertAfter(newNode);
	}
}

// ��ӡ���нڵ�ֵ(ö������ѡ�������������ǿո��ǻ���)
enum AppendNewline
{
	noNewline,
	addNewline
};
template < class T >
void PrintList(Node< T >* head, AppendNewline addnl)
{
	Node< T > * currPtr = head;
	while (currPtr != NULL)
	{
		if (addnl == addNewline)
			cout << currPtr->data << endl;
		else
			cout << currPtr->data << "  ";
		currPtr = currPtr->NextNode();
	}
}

// ɾ����㣨��ͷ��ɾ����
template <class T>
void DeleteFront(Node< T > * & head)
{
	Node< T > * ptr = head;
	if (head != NULL)
	{
		head = head->NextNode();
		delete ptr;
	}
}

// ͨ��ɾ����㣨ɾ�����е�һ�����ֵ��ȵĵ㣩
template <class T>
void Delete(Node< T > * & head, T key)
{
	// currPtr������prevPtr�������
	Node< T > * currPtr = head;
	Node< T > * prevPtr = NULL;
	if (head != NULL)
	{
		while (currPtr != NULL && currPtr->data != key)
		{
			prevPtr = currPtr;
			currPtr = currPtr->NextNode();
		}
		prevPtr->NextNode = currPtr->NextNode;
		if (currPtr != NULL)
		{
			if (currPtr == head)
				head = head->NextNode();
			else
				prevPtr->DeleteAfter();
			delete currPtr;
		}
	}
}

#endif