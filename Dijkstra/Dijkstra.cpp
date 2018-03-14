
#include "Dijkstra.h"

Graph_DG::Graph_DG(int vertexNum, int edgeNum)
{
	this->vertexNum = vertexNum;
	this->edgeNum = edgeNum;

	// 将图的邻接矩阵值均初始化为INT_MAX
	vector<int> tmp;
	for (int i = 0; i < vertexNum; i++){
		tmp.clear();
		for (int j = 0; j < vertexNum; j++)
			tmp.push_back(INT_MAX);
		matrix.push_back(tmp);
	}
}

bool Graph_DG::check_input_edge(int start, int end, int weight)
{
	if (start < 0 || start >= vertexNum || end < 0 || end >= vertexNum || weight <= 0)
		return false;
	return true;
}

void Graph_DG::init()
{
	int start;
	int end;
	int weight;

	//为DIS对象开辟空间
	dis = new DIS[vertexNum];

	cout << "please input edge(start, end, weight, start from Num.0): " << endl;
	while (edgeNum--)
	{
		cin >> start >> end >> weight;
		while (!check_input_edge(start, end, weight)){
			cout << "input illegal, please input again!" << endl;
			cin >> start >> end >> weight;
		}
		matrix[start][end] = weight;
	}
	cout << "your matrix is: " << endl;
	printMatrix();
}

void Graph_DG::printMatrix()
{
	for (int i = 0; i < vertexNum; i++){
		for (int j = 0; j < vertexNum; j++)
		{
			if (matrix[i][j] == INT_MAX)
				cout << "∞" << " ";
			else
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph_DG::Dijkstra(int begin)
{
	// 首先初始化Dis数组
	for (int i = 0; i < vertexNum; i++){

		// 起始结点visit初始化为true
		if (i == begin){ 
			dis[i].path = "v" + to_string(begin);
			dis[i].value = 0;
			dis[i].visit = true;
		}
		else{
			dis[i].path = "v" + to_string(begin) + " --> v" + to_string(i);
			dis[i].value = matrix[begin][i];
		}
	}
	
	// 进行vertexNum - 1轮寻路
	for (int i = 0; i < vertexNum - 1; i++) 
	{
		// index存储当前dis数组中最小值的下标，min记录当前路径最小值
		int index = begin;
		int min = INT_MAX;

		// 更新dis数组值
		for (int j = 0; j < vertexNum; j++) 
		{
			if (!dis[j].visit && dis[j].value < min) // 每轮都是针对当前未找到最短路径的点
			{
				min = dis[j].value;
				index = j;
			}
		}

		// 如果在vertexNum - 1次寻路前找完所有可达路径，则结束寻路
		if (index == begin) 
			break;

		dis[index].visit = true; //一次寻路找到最短路径的点标记为true（已访问）

		// 更新dis数组值：对于可达路径点将其dis更新为前驱结点路径值 + 前驱结点到当前节点值 
		for (int k = 0; k < vertexNum; k++)
		{
			if (!dis[k].visit && matrix[index][k] != INT_MAX && (dis[index].value + matrix[index][k] < dis[k].value))
			{
				dis[k].value = dis[index].value + matrix[index][k];
				dis[k].path = dis[index].path + " --> v" + to_string(k);
			}
		}
		
		// 逐次打印寻路结果
		cout << endl << "第" << i << "轮" << endl;
		for (int t = 0; t < vertexNum; t++)
		{
			if (t == begin)
				continue;
			cout << dis[t].path << " " << dis[t].value << " " << dis[t].visit << endl;
		}
		
	}
	printPath(begin);
}

void Graph_DG::printPath(int begin)
{
	cout << endl << "shortest path from v" << begin << " to the other vertex are :" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		if (i != begin)
		{
			if (dis[i].value != INT_MAX)
				cout << "v" << begin << " to v" << i << ": path = " << dis[i].path << ", value = " <<  dis[i].value << endl;
			else
				cout << "v" << begin << " to v" << i << ": path = NULL, value = ∞" << endl;
		}
	}
}