
/****************************************************************
*
*              Filename: treeprint.h
*           Description: 打印树
*
***************************************************************/

#ifndef TREEPRINT_H_INCLUDE
#define TREEPRINT_H_INCLUDE

#include <iostream>
#include "treenode.h"

const int indentBlock = 6;
// 经当前行插入num个空格
void IndentBlock(int num)
{
	while (num--)
		std::cout << " ";
}

// 打印（逆向旋转90°后的）树
template <class T>
void PrintTree(TreeNode<T> *root, int level)
{
	if (root)
	{
		PrintTree(root->Right(), level + 1);
		IndentBlock(indentBlock * level);
		cout << root->data << endl;
		PrintTree(root->Left(), level + 1);
	}
}

// 打印垂直树
template <class T>
void PrintVTree(TreeNode<T> *root)
{
	
}

#endif