#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

#include "treelib.h"

using namespace std;

struct student
{
	string ssn;
	string name;
	float gpa;
};

int main()
{
	streambuf *readbuf = cin.rdbuf();
	streambuf *writebuf = cout.rdbuf();

	ifstream fin;
	ofstream fout;

	fin.open("data.in");
	fout.open("data.out");

	cin.rdbuf(fin.rdbuf());
	cout.rdbuf(fout.rdbuf());

	/*********************************************************************************/
	
	int n;
	cin >> n;
	while (n--)
	{
		int countLeaf = 0;
		TreeNode<char> *root, *rootcopy;
		MakeTree(root);
		rootcopy = CopyTree(root);
		CountLeaf(root, countLeaf);

		cout << "先序遍历（递归）： ";
		PreOrderTraverse(root);
		cout << endl;
		cout << "先序遍历（迭代）： ";
		PreOrderTraverse_iterationly(root);
		cout << endl;
		cout << "中序遍历（递归）： ";
		InOrderTraverse(root);
		cout << endl;
		cout << "中序遍历（迭代）： ";
		InOrderTraverse_iterationly(root);
		cout << endl;
		cout << "后序遍历（递归）： ";
		PostOrderTraverse(root);
		cout << endl;
		cout << "后序遍历（迭代）： ";
		PostOrderTraverse_iterationly(root);
		cout << endl;
		cout << "层次遍历： ";
		LevelOrderTraverse(root);
		cout << endl;
		cout << "叶子数目： " << countLeaf << endl;
		cout << "树的深度： " << Depth(root) << endl;
		cout << "复制的树：" << endl;
		PrintTree(rootcopy, 0);
	}
	
	/*********************************************************************************/

	cin.rdbuf(readbuf);
	cout.rdbuf(writebuf);

	fin.close();
	fout.close();
	return 0;
}