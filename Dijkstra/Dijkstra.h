
#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

// 记录起点到每个顶点路径的有关信息
struct DIS
{
	string path; // 路径
	int value; // 当前路径总权值
	bool visit; //是否访问过
	
	//构造函数，将路径初始化为空，权值初始化为0，访问性初始化为false
	DIS() 
	{
		path = "";
		value = 0;
		visit = false;
	}
};

//图类
class Graph_DG {

	int vertexNum; // 图顶点数目
	int edgeNum; // 图边数
	vector<vector<int> > matrix; // 图的邻接矩阵
	DIS *dis; // 图中起点到每个顶点路径

public:

	// 构造函数，接收顶点数和边数输入并将矩阵值初始化为INT_MAX
	Graph_DG(int vertexNum, int edgeNum);
	
	~Graph_DG(){
		matrix.clear();
	}
	
	// 检查边的输入是否合法
	bool check_input_edge(int start, int end, int weight);
	
	// 初始化函数，接收输入构造图的邻接矩阵
	void init();

	// 打印邻接矩阵
	void printMatrix();

	// Dijkstra算法，求最短路径
	void Dijkstra(int begin);

	// 打印最短路径
	void printPath(int begin);
};

#endif