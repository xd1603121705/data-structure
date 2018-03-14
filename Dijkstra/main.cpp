
/*
 *        description：迪杰斯特拉算法的C++实现
 *		       author：lijunjun
 *               date：2018/3/14
 *			    email：junlee_happy@163.com
 */

#include <fstream>

#include "Dijkstra.h"

//检验输入边数和顶点数的值是否有效，可以自己推算为啥：
//顶点数和边数的关系是：((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}

int main()
{
	// 下面一系列操作为将输入输出重定向到文件data.in和data.out中，方便调试、测试时数据键入的繁琐
	streambuf *readbuf = cin.rdbuf();   // 备份原来的输入，即标准输入  
	streambuf *writebuf = cout.rdbuf(); // 备份原来的输出，即标准输出  
	ifstream fin;    // 读文件标识符  
	ofstream fout;   // 写文件标识符  
	string test;     // 测试字符串  

	fin.open("data.in");    // 从data.in文件读  
	fout.open("data.out");  // 输出到data.out文件  

	cin.rdbuf(fin.rdbuf());    // 输入重定向  
	cout.rdbuf(fout.rdbuf());  // 输出重定向  

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

	// WARNING: 这里千万不能图省事直接用循环来找任一结点到其他节点的最短路径！！！
	//          因为一次执行将会改变dis数组的值，不能正确得出下次执行的结果！！！
	cin >> begin;
	while (begin < 0 || begin >= vertexNum)
	{
		cout << "begin input illegal! please input again(0 < begin < vertexNum): ";
		cin >> begin;
	}
	
	G.Dijkstra(begin);
	

	cin.rdbuf(readbuf);       // 输入重定向回控制台  
	cout.rdbuf(writebuf);     // 输出重定向回控制台  

	fin.close();    // 关闭文件  
	fout.close();   // 关闭文件  

	return 0;
}