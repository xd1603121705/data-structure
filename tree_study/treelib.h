
/****************************************************************
*
*              Filename: treelib.h
*           Description: �������ĸ��ֲ�����������ɾ����㣬������������������֣�������������Ҷ�ӽ��������������ȣ�
*
***************************************************************/

#ifndef TREELIB_H_INCLUDE
#define TREELIB_H_INCLUDE

#include "treenode.h"
#include "treeprint.h"

template <class T>
TreeNode<T>* TreeNode<T>::Left(void) const
{
	return this->left;
}

template <class T>
TreeNode<T>* TreeNode<T>::Right(void) const
{
	return this->right;
}

// �����½��
template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T> *lptr = NULL, TreeNode<T> *rptr = NULL)
{
	TreeNode<T> *p;
	p = new TreeNode<T>(item, lptr, rptr);
	if (!p)
	{
		cerr << "Memory allocation failure" << endl;
		return 0;
	}
	return p;
}

// �ͷ����������Ķ�̬�ڴ�
template <class T>
void FreeTreeNode(TreeNode<T> *p)
{
	delete p;
}
/*
// ��������򴴽��� 
// ģ�庯�������Զ�ʶ�𷵻�ֵ������ô��
template <class T>
auto MakeTree()->decltype(TreeNode<T>*)
{
	T data;
	cin >> data;
	if (data == '#')
		return;
	else
	{
		TreeNode<T> *root = new TreeNode<T>(data);
		root->Left() = MakeTree();
		root->Right() = MakeTree();
	}
	return root;
}
*/

template <class T>
void MakeTree(TreeNode<T> *&root)
{
	T data;
	cin >> data;
	if (data == '#')
		root = NULL;
	else
	{
		root = new TreeNode<T>(data);
		MakeTree(root->left);
		MakeTree(root->right);
	}
}


// ������������ݹ�(recursionly)��
template <class T>
void PreOrderTraverse(TreeNode<T> *root)
{
	if (root)
	{
		cout << root->data << " ";
		PreOrderTraverse(root->Left());
		PreOrderTraverse(root->Right());
	}
	return;
}

// ������������ǵݹ�(iterationly)��
template <class T>
void PreOrderTraverse_iterationly(TreeNode<T> *root)
{
	TreeNode<T> *t = root;
	std::stack<TreeNode<T>*> s; // ������ջ
	while (t || !s.empty())
	{
		while (t)               // һֱ���󲢽���;���ѹջ
		{
			s.push(t);
			cout << t->data << " ";
			t = t->Left();
		}
		if (!s.empty())
		{
			t = s.top();
			s.pop();
			t = t->Right();
		}
	}
}

// ���������
template <class T>
void InOrderTraverse(TreeNode<T> *root)
{
	if (root)
	{
		InOrderTraverse(root->Left());
		cout << root->data << " ";
		InOrderTraverse(root->Right());
	}
	return;
}

// ������������ǵݹ�(iterationly)��
template <class T>
void InOrderTraverse_iterationly(TreeNode<T> *root)
{
	TreeNode<T> *t = root;
	std::stack<TreeNode<T>*> s; // ������ջ
	while (t || !s.empty())
	{
		while (t)               // һֱ���󲢽���;���ѹջ
		{
			s.push(t);
			t = t->Left();
		}
		if (!s.empty())
		{
			t = s.top();
			s.pop();
			cout << t->data << " ";
			t = t->Right();
		}
	}
}

// ���������
template <class T>
void PostOrderTraverse(TreeNode<T> *root)
{
	if (root)
	{
		PostOrderTraverse(root->Left());
		PostOrderTraverse(root->Right());
		cout << root->data << " ";
	}
	return;
}

// ������������ǵݹ�(iterationly)��
template <class T>
void PostOrderTraverse_iterationly(TreeNode<T> *root)
{
	TreeNode<T> *t = root, *haveVisited = NULL;
	std::stack<TreeNode<T>*> s; // ������ջ
	while (t || !s.empty())
	{
		while (t)               // һֱ���󲢽���;���ѹջ
		{
			s.push(t);
			t = t->Left();
		}
		if (!s.empty())
		{
			t = s.top();
			if (!t->Right() || haveVisited == t->Right())
			{
				cout << t->data << " ";
				s.pop();
				haveVisited = t;
				t = NULL;
			}
			else
				t = t->Right();
		}
	}
}

// ��α�����
template <class T>
void LevelOrderTraverse(TreeNode<T> *root)
{
	std::queue<TreeNode<T>*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode<T> *t = q.front();
		cout << t->data << " ";
		q.pop();
		if (t->Left())
			q.push(t->Left());
		if (t->Right())
			q.push(t->Right());
	}
}

// ��������Ҷ�ӽ����,�������
template <class T>
void CountLeaf(TreeNode<T> *root, int &count)
{
	if (root)
	{
		CountLeaf(root->Left(), count);
		CountLeaf(root->Right(), count);
		if (root->Left() == NULL && root->Right() == NULL)
			++count;
	}
}

// ����������ȣ��������Ϊ0��,���������
template < class T >
int Depth(TreeNode<T> *root)
{
	int depthLeft, depthRight, depthval;
	if (!root)
		depthval = 0;
	else
	{
		depthLeft = Depth(root->Left());
		depthRight = Depth(root->Right());
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	return depthval;
}

// ��дתСд
char LowerCase(char CH)
{
	char ch = tolower(CH);
	return ch;
}

// ����ɨ�踴����
template <class T>
TreeNode<T>* CopyTree(TreeNode<T> *root)
{
	TreeNode<T> *newlptr, *newrptr, *newnode;
	if (!root)
		return NULL;
	else
	{
		newlptr = CopyTree(root->Left());
		newrptr = CopyTree(root->Right());
		newnode = GetTreeNode(LowerCase(root->data), newlptr, newrptr);
	}
	return newnode;
}

// ����ɨ��ɾ����
template <class T>
void DeleteTree(TreeNode<T> *root)
{
	if (root)
	{
		DeleteTree(root->Left());
		DeleteTree(root->Left());
		FreeTreeNode(root);
	}
}

// ���ú���DeleteTree�ͷ����н�㣬Ȼ��ָ����ΪNULL
template <class T>
void ClearTree(TreeNode<T> *&root)
{
	DeleteTree(root);
	root = NULL;
}

#endif