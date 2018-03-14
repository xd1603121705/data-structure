
#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

// ��¼��㵽ÿ������·�����й���Ϣ
struct DIS
{
	string path; // ·��
	int value; // ��ǰ·����Ȩֵ
	bool visit; //�Ƿ���ʹ�
	
	//���캯������·����ʼ��Ϊ�գ�Ȩֵ��ʼ��Ϊ0�������Գ�ʼ��Ϊfalse
	DIS() 
	{
		path = "";
		value = 0;
		visit = false;
	}
};

//ͼ��
class Graph_DG {

	int vertexNum; // ͼ������Ŀ
	int edgeNum; // ͼ����
	vector<vector<int> > matrix; // ͼ���ڽӾ���
	DIS *dis; // ͼ����㵽ÿ������·��

public:

	// ���캯�������ն������ͱ������벢������ֵ��ʼ��ΪINT_MAX
	Graph_DG(int vertexNum, int edgeNum);
	
	~Graph_DG(){
		matrix.clear();
	}
	
	// ���ߵ������Ƿ�Ϸ�
	bool check_input_edge(int start, int end, int weight);
	
	// ��ʼ���������������빹��ͼ���ڽӾ���
	void init();

	// ��ӡ�ڽӾ���
	void printMatrix();

	// Dijkstra�㷨�������·��
	void Dijkstra(int begin);

	// ��ӡ���·��
	void printPath(int begin);
};

#endif