
/*
 *        description���Ͻ�˹�����㷨��C++ʵ��
 *		       author��lijunjun
 *               date��2018/3/14
 *			    email��junlee_happy@163.com
 */

#include <fstream>

#include "Dijkstra.h"

//������������Ͷ�������ֵ�Ƿ���Ч�������Լ�����Ϊɶ��
//�������ͱ����Ĺ�ϵ�ǣ�((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}

int main()
{
	// ����һϵ�в���Ϊ����������ض����ļ�data.in��data.out�У�������ԡ�����ʱ���ݼ���ķ���
	streambuf *readbuf = cin.rdbuf();   // ����ԭ�������룬����׼����  
	streambuf *writebuf = cout.rdbuf(); // ����ԭ�������������׼���  
	ifstream fin;    // ���ļ���ʶ��  
	ofstream fout;   // д�ļ���ʶ��  
	string test;     // �����ַ���  

	fin.open("data.in");    // ��data.in�ļ���  
	fout.open("data.out");  // �����data.out�ļ�  

	cin.rdbuf(fin.rdbuf());    // �����ض���  
	cout.rdbuf(fout.rdbuf());  // ����ض���  

	//getline(cin, test);
	//cout << test << "!";


	int vertexNum;
	int edgeNum;
	cout << "please input vertexNum and edgeNum " << endl;
	cin >> vertexNum >> edgeNum;
	while (!check(vertexNum, edgeNum))
	{
		cout << "input illegal, please input again!" << endl;
		cin >> vertexNum >> edgeNum;
	}
	
	Graph_DG G(vertexNum, edgeNum);
	G.init();
	cout << "please input start vertex: " << endl;
	int begin;

	// WARNING: ����ǧ����ͼʡ��ֱ����ѭ��������һ��㵽�����ڵ�����·��������
	//          ��Ϊһ��ִ�н���ı�dis�����ֵ��������ȷ�ó��´�ִ�еĽ��������
	cin >> begin;
	while (begin < 0 || begin >= vertexNum)
	{
		cout << "begin input illegal! please input again(0 < begin < vertexNum): ";
		cin >> begin;
	}
	
	G.Dijkstra(begin);
	

	cin.rdbuf(readbuf);       // �����ض���ؿ���̨  
	cout.rdbuf(writebuf);     // ����ض���ؿ���̨  

	fin.close();    // �ر��ļ�  
	fout.close();   // �ر��ļ�  

	return 0;
}