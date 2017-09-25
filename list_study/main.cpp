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
	// ��ҵ������
	// ����studrecs.txt�ļ�������¼��������graduatelist��ɾ��GPA����2.0��ѧ��������noattend.txt�ļ�����ɾ�������ѧ��
	Node< StudentRecord > * graduateList = NULL,  // ѧ����Ϣ����
		*currPtr, *prevPtr, // �����ĵ�ǰָ�룬ǰһָ��
		*deleteNodePtr;     // ��ɾ���Ľ��ָ��
	StudentRecord srec;     // ѧ����Ϣ
	ifstream fin;           
	fin.open("studrecs.txt", ios::in | ios::_Nocreate); 
	if (! fin)
	{
		cerr << "Cannot open file studrecs.txt." << endl;
		return 1;
	}
	// ��һλС�����GPAֵ
	cout.setf(ios::fixed);
	cout.precision(1);
	cout.setf(ios::showpoint);

	// ��srec�����ͷ
	while (fin >> srec) // ��Ҫ���ж���һ�� >> �����غ���
		//InsertFront(graduateList, srec); // ͷ�巨
		InsertRear(graduateList, srec);

	// ��ӡ����ѧ����������Ϊʹ�õ�ͷ�巨��
	cout << "All students and GPA are:" << endl;
	PrintList(graduateList, addNewline);

	//ɾ��GPA����2.0��ѧ��
	prevPtr = NULL;
	currPtr = graduateList;
	deleteNodePtr = NULL;
	while (currPtr != NULL)
	{
		// ��ѧ���Ƿ��ܱ�ҵ
		if (currPtr->data.gpa < 2.0)
		{
			// ��ѧ���Ƿ���ͷ���
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
		// �ܱ�ҵ����ɾ����ָ��ֱ�Ӻ���
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
	// ���ļ��ж������òμӱ�ҵ�����ѧ�����Ӷ�����ɾ��
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
		else if (prevPtr == NULL) // Ҫɾ����ѧ��Ϊͷ���
		{
			graduateList = currPtr->NextNode();
			//currPtr->DeleteAfter();
			deleteNodePtr = currPtr;
			delete deleteNodePtr;
			currPtr = graduateList;
		}
		else                      // ɾ��ѧ��
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

	// ȥ��noattend.txt�ļ��е�ѧ��

	/*
	// ����������
	// ����һ���ַ���������rand() % 2 ��ֵ�����ַ����е��ַ�����InsertFront����InsertRear
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
	
	// program2������10��1-10�ڵ������������㲢��������
	// �����û�����key������list��key���ֵĴ��� 
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