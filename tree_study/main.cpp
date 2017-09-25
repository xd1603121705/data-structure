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

		cout << "����������ݹ飩�� ";
		PreOrderTraverse(root);
		cout << endl;
		cout << "����������������� ";
		PreOrderTraverse_iterationly(root);
		cout << endl;
		cout << "����������ݹ飩�� ";
		InOrderTraverse(root);
		cout << endl;
		cout << "����������������� ";
		InOrderTraverse_iterationly(root);
		cout << endl;
		cout << "����������ݹ飩�� ";
		PostOrderTraverse(root);
		cout << endl;
		cout << "����������������� ";
		PostOrderTraverse_iterationly(root);
		cout << endl;
		cout << "��α����� ";
		LevelOrderTraverse(root);
		cout << endl;
		cout << "Ҷ����Ŀ�� " << countLeaf << endl;
		cout << "������ȣ� " << Depth(root) << endl;
		cout << "���Ƶ�����" << endl;
		PrintTree(rootcopy, 0);
	}
	
	/*********************************************************************************/

	cin.rdbuf(readbuf);
	cout.rdbuf(writebuf);

	fin.close();
	fout.close();
	return 0;
}