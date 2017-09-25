
/****************************************************************
*
*              Filename: treeprint.h
*           Description: ��ӡ��
*
***************************************************************/

#ifndef TREEPRINT_H_INCLUDE
#define TREEPRINT_H_INCLUDE

#include <iostream>
#include "treenode.h"

const int indentBlock = 6;
// ����ǰ�в���num���ո�
void IndentBlock(int num)
{
	while (num--)
		std::cout << " ";
}

// ��ӡ��������ת90���ģ���
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

// ��ӡ��ֱ��
template <class T>
void PrintVTree(TreeNode<T> *root)
{
	
}

#endif