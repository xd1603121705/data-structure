
/****************************************************************
*
*              Filename: treelib.h
*           Description: 对树结点的各种操作（创建、删除结点，建树，清空树，（各种）遍历树，计算叶子结点数，计算树深度）
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

// 创建新结点
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

// 释放与结点相连的动态内存
template <class T>
void FreeTreeNode(TreeNode<T> *p)
{
	delete p;
}
/*
// 按先序次序创建树 
// 模板函数不能自动识别返回值，，怎么办
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


// 先序遍历树（递归(recursionly)）
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

// 先序遍历树（非递归(iterationly)）
template <class T>
void PreOrderTraverse_iterationly(TreeNode<T> *root)
{
	TreeNode<T> *t = root;
	std::stack<TreeNode<T>*> s; // 创建堆栈
	while (t || !s.empty())
	{
		while (t)               // 一直向左并将沿途结点压栈
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

// 中序遍历树
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

// 中序遍历树（非递归(iterationly)）
template <class T>
void InOrderTraverse_iterationly(TreeNode<T> *root)
{
	TreeNode<T> *t = root;
	std::stack<TreeNode<T>*> s; // 创建堆栈
	while (t || !s.empty())
	{
		while (t)               // 一直向左并将沿途结点压栈
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

// 后序遍历树
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

// 中序遍历树（非递归(iterationly)）
template <class T>
void PostOrderTraverse_iterationly(TreeNode<T> *root)
{
	TreeNode<T> *t = root, *haveVisited = NULL;
	std::stack<TreeNode<T>*> s; // 创建堆栈
	while (t || !s.empty())
	{
		while (t)               // 一直向左并将沿途结点压栈
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

// 层次遍历树
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

// 计算树中叶子结点数,后序遍历
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

// 计算树的深度（空树深度为0）,后序遍历树
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

// 大写转小写
char LowerCase(char CH)
{
	char ch = tolower(CH);
	return ch;
}

// 后序扫描复制树
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

// 后序扫描删除树
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

// 调用函数DeleteTree释放所有结点，然后将指针置为NULL
template <class T>
void ClearTree(TreeNode<T> *&root)
{
	DeleteTree(root);
	root = NULL;
}

#endif