#ifndef INCLUDE_NODE_H
#define INCLUDE_NODE_H
#include <stdlib.h>

template <class T>
	class Node
	{
	private:
		// nextΪָ����һ����ָ��
		Node< T > *next; 
	public:
		// dataΪ���г�Ա
		T data; 
		// ���캯��
		Node(const T& item, Node< T > * ptrnext = NULL); 
		// �޸ı�ķ���
		void InsertAfter(Node< T > * p); // p�������
		Node< T > * DeleteAfter(void); //
		// ������һ����ָ��
		Node< T > * NextNode(void) const;
		void SetNext(const Node< T > * p);
	};

	template <class T>
	Node< T >::Node(const T& item, Node< T > * ptrnext)
	{
		this->data = item;
		this->next = ptrnext;
	}

	template <class T>
	void Node< T >::InsertAfter(Node< T > * p)
	{
		p->next = this->next;
		this->next = p;
	}

	template <class T>
	Node< T > * Node< T >::DeleteAfter(void)
	{
		Node< T > *p;
		p = this->next;
		if (this->next == NULL)
			return NULL;
		delete this->next;
		this->next = p->next;
		return p;
	}

	template <class T>
	Node< T > * Node< T >::NextNode(void) const
	{
		return this->next;
	}

	template <class T>
	void Node< T >::SetNext(const Node< T > * p)
	{
		this->next = p->NextNode();
	}

	/*
	template <class T>
	Node<T>::Node(const T& item, Node< T > * ptrnext);

	template <class T>
	void Node< T >::InsertAfter(Node< T > * p);

	template <class T>
	Node< T > * Node< T >::DeleteAfter(void);

	template <class T>
	Node< T > * Node< T >::NextNode(void) const;
	*/
#endif