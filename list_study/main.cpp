#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>

#include "node.h"
#include "nodelib.h"
#include "studinfo.h"

using namespace std;

int main()
{
	// 毕业生名单
	// 读入studrecs.txt文件，将记录插入链表graduatelist，删掉GPA低于2.0的学生，读入noattend.txt文件，再删掉里面的学生
	Node< StudentRecord > * graduateList = NULL,  // 学生信息链表
		*currPtr, *prevPtr, // 遍历的当前指针，前一指针
		*deleteNodePtr;     // 待删除的结点指针
	StudentRecord srec;     // 学生信息
	ifstream fin;           
	fin.open("studrecs.txt", ios::in | ios::_Nocreate); 
	if (! fin)
	{
		cerr << "Cannot open file studrecs.txt." << endl;
		return 1;
	}
	// 用一位小数输出GPA值
	cout.setf(ios::fixed);
	cout.precision(1);
	cout.setf(ios::showpoint);

	// 将srec插入表头
	while (fin >> srec) // 需要自行定义一个 >> 的重载函数
		//InsertFront(graduateList, srec); // 头插法
		InsertRear(graduateList, srec);

	// 打印所有学生（逆序，因为使用的头插法）
	cout << "All students and GPA are:" << endl;
	PrintList(graduateList, addNewline);

	//删除GPA低于2.0的学生
	prevPtr = NULL;
	currPtr = graduateList;
	deleteNodePtr = NULL;
	while (currPtr != NULL)
	{
		// 该学生是否能毕业
		if (currPtr->data.gpa < 2.0)
		{
			// 该学生是否是头结点
			if (prevPtr == NULL)
			{
				graduateList = currPtr->NextNode();
				//currPtr->DeleteAfter();
				deleteNodePtr = currPtr;
				delete deleteNodePtr;
				currPtr = graduateList;
			}
			else
			{
				Node< StudentRecord > *p;
				p = currPtr;
				prevPtr->SetNext(currPtr);
				currPtr = currPtr->NextNode();
				delete p;
				//deleteNodePtr = prevPtr->DeleteAfter();
				//delete deleteNodePtr;
			}
		}
		// 能毕业，不删除，指针直接后移
		else
		{
			prevPtr = currPtr;
			currPtr = currPtr->NextNode();
		}
	}
	fin.close();

	cout << "students can graduate( GPA > 2.0 ):" << endl;
	PrintList(graduateList, addNewline);

	fin.open("noattend.txt", ios::in | ios::_Nocreate);
	if (!fin)
	{
		cerr << "Cannot open file noattend.txt." << endl;
		return 1;
	}
	// 从文件中读出不用参加毕业典礼的学生并从队列中删除
	string name;
	cout << "students noattend:";
	while (getline(fin, name))
	{
		cout << " " << name;
		prevPtr = NULL;
		currPtr = graduateList;
		deleteNodePtr = NULL;
		while (currPtr != NULL && currPtr->data.name != name)
		{
			prevPtr = currPtr;
			currPtr = currPtr->NextNode();
		}
		if (currPtr == NULL)
			continue;
		else if (prevPtr == NULL) // 要删除的学生为头结点
		{
			graduateList = currPtr->NextNode();
			//currPtr->DeleteAfter();
			deleteNodePtr = currPtr;
			delete deleteNodePtr;
			currPtr = graduateList;
		}
		else                      // 删除学生
		{
			Node< StudentRecord > *p;
			p = currPtr;
			prevPtr->SetNext(currPtr);
			currPtr = currPtr->NextNode();
			delete p;
		}
	}

	cout << endl << "Students attending graduation:" << endl;
	PrintList(graduateList, addNewline);
	fin.close();

	// 去掉noattend.txt文件中的学生

	/*
	// 生成乱码字
	// 输入一个字符串，根据rand() % 2 的值决定字符串中的字符调用InsertFront还是InsertRear
	string word;
	Node < char > * head = NULL;
	srand((unsigned)time(0));
	cout << "input word: ";
	getline(cin, word);
	for (int i = 0; i < word.size(); i++)
	{
		if (rand() % 2 == 0)
			InsertFront(head, word[i]);
		else
			InsertRear(head, word[i]);
	}
	cout << "word is: " << word << endl;
	PrintList(head, noNewline);
	cout << endl;
	*/


	/*
	
	// program2：产生10个1-10内的随机数产生结点并构造链表，
	// 接受用户输入key，返回list中key出现的次数 
	Node< int > * head = NULL, *currPtr;
	srand((unsigned)time(0));
	int i, key, count = 0;
	for (i = 0; i < 10; i++)
		InsertFront(head, rand() % 10 + 1);
	cout << "List: ";
	PrintList(head, noNewline);
	cout << endl << "Enter a key: ";
	cin >> key;
	currPtr = head;
	while (currPtr != NULL)
	{
		if (currPtr->data == key)
			++count;
		currPtr = currPtr->NextNode();
	}

	cout << "The data value " << key << " occurs " << count << " times in the list" << endl;
	*/

	/*
	// program 1
	Node<int> t(10);

	Node<int> * u;
	u = new Node<int>(20);

	Node<char> *p, *q, *r;
	q = new Node<char>('B');
	p = new Node<char>('A', q);
	r = new Node<char>('C');
	q->InsertAfter(r);
	cout << p->data;
	p = p->NextNode();
	cout << p->data;
	cout << endl;
	r = q->DeleteAfter();*/

	return 0;
}