
/****************************************************************
*
*              Filename: treenode.h
*           Description: 树结点的定义
*
***************************************************************/

#ifndef TREENODE_H_INCLUDE
#define TREENODE_H_INCLUDE

// BinSTree依赖于TreeNode
template <class T>
class BinSTree;

template <class T>
class TreeNode
{
public:
	// 结点值
	T data;
	// 指向左右孩子结点的指针
	TreeNode<T> *left;
	TreeNode<T> *right;
	// 构造函数
	TreeNode(const T &item, TreeNode<T> *lptr = NULL, TreeNode<T> *rptr = NULL) :data(item), left(lptr), right(rptr){}

	/*
	// 成员函数
	TreeNode<T>* GetTreeNode(T item, TreeNode<T> *lptr = NULL, TreeNode<T> *rptr = NULL);
	void FreeTreeNode(TreeNode<T> *p);
	*/

	// 访问指针域的函数
	TreeNode<T>* Left(void) const;
	TreeNode<T>* Right(void) const;

	// 设置孩子指针
	

	// BinSTree要访问结点的左右指针，所以设计为友元类
	friend class BinSTree < T > ;
	
};

#endif