/****************************************************************
*
*              Filename: BinSTree.h
*           Description: 二叉搜索树类
*
***************************************************************/

#ifndef BINSTREE_H_INCLUDE
#define BINSTREE_H_INCLUDE

#include "treenode.h"

template <class T>
class BinSTree
{
protected:
	// 指向树根及当前结点
	TreeNode<T> *root;
	TreeNode<T> *current;
	// 树中数据项个数
	int size;

	// 申请、释放内存
	TreeNode<T>* GetTreeNode(const T& item, TreeNode<T> *lptr, TreeNode<T> *rptr);
	void FreeTreeNode(TreeNode<T> *node);

	// 用于复制构造函数及赋值运算符
	TreeNode<T>* CopyTree(TreeNode<T> *root);

	// 用于析构函数、赋值运算符及ClearList方法
	void DeleteTree(TreeNode<T> *root);

	// 用于Find和Delete中用来定位结点及其双亲在树中的位置
	TreeNode<T> *FindNode(const T &item, TreeNode<T> *&parent) const;
public:
	// 构造函数和析构函数
	BinSTree(void);
	BinSTree(const BinSTree<T> &tree)
	{
		*this = tree;
	}
	~BinSTree(void)
	{
		DeleteTree(this);
	}

	// 赋值运算符
	BinSTree<T> &operator = (const BinSTree<T> &rhs);

	// 标准的表处理方法
	int Find(T &item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList(void);
	int ListEmpty(void) const;
	int ListSize(void) const;

	// 树的特殊方法
	void Update(const T& item);
	TreeNode<T> *GetRoot(void) const;
};

template <class T>
TreeNode<T>* BinSTree<T>::GetTreeNode(const T& item, TreeNode<T> *lptr, TreeNode<T> *rptr){
	TreeNode<T> *node = new TreeNode<T>(item, lptr, rptr);
	return node;
}

template <class T>
void BinSTree<T>::FreeTreeNode(TreeNode<T> *node){
	delete node;
}

// 后序扫描复制树
template <class T>
TreeNode<T>* BinSTree<T>::CopyTree(TreeNode<T> *t)
{
	TreeNode<T> *newlptr, *newrptr, *newnode;
	if (!t)
		return NULL;
	else
	{
		newlptr = CopyTree(t->Left());
		newrptr = CopyTree(t->Right());
		newnode = GetTreeNode(LowerCase(t->data), newlptr, newrptr);
	}
	return newnode;
}

// 后序扫描删除树
template <class T>
void BinSTree<T>::DeleteTree(TreeNode<T> *t)
{
	if (t)
	{
		DeleteTree(t->Left());
		DeleteTree(t->Left());
		FreeTreeNode(t);
	}
}

// 用于Find和Delete中用来定位结点及其双亲在树中的位置
template <class T>
TreeNode<T>* BinSTree<T>::FindNode(const T &item, TreeNode<T> *&parent) const{
	// 用指针T从根开始遍历
	TreeNode<T> *t = root;
	// 根的双亲为NULL
	parent = NULL;
	// 若子树为空，则循环结束
	while (t)
	{
		if (item == t->data)
			break;
		else
		{
			// 修改双亲结点，改到左子树或右子树
			parent = t;
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}
	}
	return t;
}

// 赋值运算符
template <class T>
BinSTree<T> &BinSTree<T>::operator = (const BinSTree<T> &rhs){
	// 不能将树复制到自身
	if (this == &rhs)
		return *this;
	// 清除当前树，将新树复制到当前对象
	ClearList();
	root = CopyTree(rhs);

	// 将current指针指向root并设置size值
	current = root;
	size = rhs.size;

	// 返回当前对象的指针
	return *this;
}

/* 表处理函数 */

template <class T>
void BinSTree<T>::Find(T& item){
	//使用 FindNo<Je » 它需要 parent 参数
	TreeNode < T > * parent；
	// 在树中搜索 item.将匹K 的结点賦给 current
	current = FindNode(item, parent);
	// 若找到，则将数据赋绐 item 并返回 True
	if (current !* NULL)
	{
		item = current - > data;
		return 1;
	}
	else
		// 在树中没找到 item,返回 False
		return 0;
}

// 往查找树中插入数据项
template < class T>
void BinSTree < T >::Insert(const T& item)
{
	//t 为遍历过程中的当前结点，parent 为前一结点
	TreeNode <T> * t = root, *parent = NULL, *newNode;
	// 若子树为空，则退出循环
	while (t != NULL)
	{
		// 修 改 parent 指针.然后往左或往右
		parent = t;
		if (item < t - > data)
			t = t - > left;
		else
			t = t - > right;
	}
	// 创建新的叶子结点
	newNode = GetTreeNode(item, NULL， NULL);
	// 若 parent 为 NULL,则将其作为根结点插入
	if (parent == NULL)
		root = newNode;
	// 若 item < parent - > data,则将其作为左孩子插入
	else if (item < parent->data)
		parent->left = newNode;
	else
		// 若 item > = parent - > data 作为右孩子括入
		parent - > right = newNode;
	// current 贼值为新结点的地址并将 size 加 1
	size++;
}

// 若 item 在树中，将其删除
template < class T >
void BinSTree< T>::Delete(const T& item)
{
	// DNodePtr = 指向被删除结点 D 的指针
	//PNodePtr = 指向结点 D 的双亲结点 p 的指针
	// RNodePtr = 指向替换 D 的结点 R 的指针
	TreeNode <T> * DNodePtr, *PNodePtr, *RNodePtr;
	// 搜索数据值为 item 的结点，并保存该结点的双亲结点的指针
	if ((DNodePtr = FindNode(item, PNodePtr)) = = NULL)
		return;
	// 若 D 有一个指针为 NULL, 则替换结点为其另一技的某一结点
	if (DNodePtr - > right = = NULL)
		RNodePtr = DNodePtr - > left;
	else if (DNodePtr - > left = = NULL)
		NodePtr = DNodePtr - > right;
	else
	{
		//DNodePtr 的两个指针均不为 MJLL
		// 寻找并卸下 D 的替换结点。 从结点 D 的左子树开始，找数据值小于 D 的数据傕的
		// 最大值，将该结点从树中断开
		// PofRNodePtr = 指向替换结点对亲的指针
		TreeNode < T > * PofRNodePtr = DNodePtr;
		// 第一种可能的替换为 D 的左孩子
		RNodePtr = DNodePtr - > left;
		// 从 D 的左孩子的右子树继续往下搜索最大值，并记录当前结点及其双亲鲒点的
		// 指针.最后，我们将找到替换结点.
		while (RNodePtr - > right != NULL)
		{
			PofRNodePtr - RNodePtr;
			RNodePtr = RNodePtr - > right;
		}
		if (PofRNodePtr = = DNodePtr)
			// 被 删 除 结 点 的 左 孩 子 为 替 换 结 点，将 D 的 右 子 树 赋 给 R
			RNodePtr - > right = DNodePtr - > right;
		else
		{
			// 至 少 往 右 予 树 移 动 了 一 个 结 点，从 树 中《除 替 换 结 点，将 其 左 子 树 赋 给 其 双 亲	
			PofRNodePtr - > right = RNodePtr - > left;
			// 用 替 换 结 点 代 替 DNodePtr*
			RNodePtr - > left = DNodePtr - > left;
			RNodePtr - > right = DNodePtr - > right;
		}
	}

	// 完 成 到 双 亲 结 点 的 连 结。 删 除 根 结 点 ，并 给 新 根 賦 值
	if (PNodePtr = = NULL)
		root = RNodePtr;
	// 将 R 连 到 P 的 正 确 一 枝 上
	else if (DNodePtr - > data < PNodePtr - > data)
		PNodePtr - > left = RNodePtr;
	else
		PNodePtr - > right = RNodePtr;
	// 释 放 被 删 结 点 内 存 并 将 树 的 大 小 减 1
	FirstTreeNode(DNodePtr);
	size - -;
}

// 若当前结点巳定义且数据值与给定数据值相等，则将结点值赋给item;否则，将item
// 插入到树中
template < class T>
void BinSTree <T>::Update(const T& item)
{
	if (current != NULL && current - > data = = item)
		current - > data = item;
	else
		Insert(item);
}

// 获取树的根结点
template <class T>
TreeNode<T>* BinSTree<T>::GetRoot(void) const{
	return root;
}

template <class T>
template <class T>
template <class T>
template <class T>
template <class T>
template <class T>



#endif