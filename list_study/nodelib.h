#ifndef INCLUDE_NODELIB_H
#define INCLUDE_NODELIB_H

#include "node.h"

// 生成结点
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

// 插入结点（头插法,head即为头结点）
template <class T>
void InsertFront(Node< T > * & head, T item)
{
	head = GetNode(item, head);
}

// 插入结点（尾插法）
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

// 打印所有节点值(枚举用来选择输出后面跟的是空格还是换行)
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

// 删除结点（从头部删除）
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

// 通用删除结点（删除表中第一个与键值相等的点）
template <class T>
void Delete(Node< T > * & head, T key)
{
	// currPtr遍历表，prevPtr紧跟其后
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