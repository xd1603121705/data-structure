
/****************************************************************
*
*              Filename: treenode.h
*           Description: �����Ķ���
*
***************************************************************/

#ifndef TREENODE_H_INCLUDE
#define TREENODE_H_INCLUDE

// BinSTree������TreeNode
template <class T>
class BinSTree;

template <class T>
class TreeNode
{
public:
	// ���ֵ
	T data;
	// ָ�����Һ��ӽ���ָ��
	TreeNode<T> *left;
	TreeNode<T> *right;
	// ���캯��
	TreeNode(const T &item, TreeNode<T> *lptr = NULL, TreeNode<T> *rptr = NULL) :data(item), left(lptr), right(rptr){}

	/*
	// ��Ա����
	TreeNode<T>* GetTreeNode(T item, TreeNode<T> *lptr = NULL, TreeNode<T> *rptr = NULL);
	void FreeTreeNode(TreeNode<T> *p);
	*/

	// ����ָ����ĺ���
	TreeNode<T>* Left(void) const;
	TreeNode<T>* Right(void) const;

	// ���ú���ָ��
	

	// BinSTreeҪ���ʽ�������ָ�룬�������Ϊ��Ԫ��
	friend class BinSTree < T > ;
	
};

#endif