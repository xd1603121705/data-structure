
#include "Dijkstra.h"

Graph_DG::Graph_DG(int vertexNum, int edgeNum)
{
	this->vertexNum = vertexNum;
	this->edgeNum = edgeNum;

	// ��ͼ���ڽӾ���ֵ����ʼ��ΪINT_MAX
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

	//ΪDIS���󿪱ٿռ�
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
				cout << "��" << " ";
			else
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph_DG::Dijkstra(int begin)
{
	// ���ȳ�ʼ��Dis����
	for (int i = 0; i < vertexNum; i++){

		// ��ʼ���visit��ʼ��Ϊtrue
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
	
	// ����vertexNum - 1��Ѱ·
	for (int i = 0; i < vertexNum - 1; i++) 
	{
		// index�洢��ǰdis��������Сֵ���±꣬min��¼��ǰ·����Сֵ
		int index = begin;
		int min = INT_MAX;

		// ����dis����ֵ
		for (int j = 0; j < vertexNum; j++) 
		{
			if (!dis[j].visit && dis[j].value < min) // ÿ�ֶ�����Ե�ǰδ�ҵ����·���ĵ�
			{
				min = dis[j].value;
				index = j;
			}
		}

		// �����vertexNum - 1��Ѱ·ǰ�������пɴ�·���������Ѱ·
		if (index == begin) 
			break;

		dis[index].visit = true; //һ��Ѱ·�ҵ����·���ĵ���Ϊtrue���ѷ��ʣ�

		// ����dis����ֵ�����ڿɴ�·���㽫��dis����Ϊǰ�����·��ֵ + ǰ����㵽��ǰ�ڵ�ֵ 
		for (int k = 0; k < vertexNum; k++)
		{
			if (!dis[k].visit && matrix[index][k] != INT_MAX && (dis[index].value + matrix[index][k] < dis[k].value))
			{
				dis[k].value = dis[index].value + matrix[index][k];
				dis[k].path = dis[index].path + " --> v" + to_string(k);
			}
		}
		
		// ��δ�ӡѰ·���
		cout << endl << "��" << i << "��" << endl;
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
				cout << "v" << begin << " to v" << i << ": path = NULL, value = ��" << endl;
		}
	}
}