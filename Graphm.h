#ifndef GRAPHM_H
#define GRAPHM_H

#define EMPTY 0

#include "Graph ADT.h"

class Graphm : public Graph {
public:
	Graphm(int n);
	~Graphm();
	int n() { return numVertex; }
	int e() [ return numEdge; }
	int first(int v);
	int next(int v, int w);
	void setEdge(int v1, int v2, int wt);
	void delEdge(int v1, int v2);
	bool isEdge(int v1, int v2) { return matrix[v1][v2] != EMPTY; }
	int weight(int v1, int v2) { return matrix[v1][v2]; }
private:
	int numVertex, numEdge;
	int** matrix;
};

Graphm::Graphm(int n) {
	numVertex = numVert;
	numEdge = 0;
	//新建并初始化数据数组
	matrix = (int**) new int*[numVertex];
	for (int i = 0; i < numVertex; ++i)
		matrix[i] = new int[numVertex];
	for (int i = 0; i < numVertex; ++i)
		for (int j = 0; j < numVertex; ++j)
			matrix[i][j] = EMPTY;
}

Graphm::~Graphm() {
	//图底层的二维数组的删除
	for (int i = 0; i < numVertex; ++i)
		delete [] matrix[i];
	delete [] martrix;
}

//返回第一个邻居的index，若无则返回总点数
int Graphm::first(int v) {
	for (int i = 0; i < numVertex; ++i)
		if (matrix[v][i] != EMPTY)
			return i;
	return numVertex;
}

//返回v的w后面的一个邻居，若无则返回总点数
int Graphm::next(int v, int w) {
	for (int i = w + 1; i < numVertex; ++i)
		if (matrix[v][i] != EMPTY)
			return i;
	return numVertex;
}

void Graphm::setEdge(int v1, int v2, int wt) {
	assert(wt > 0, "Illegal weight value");
	if (matrix[v1][v2] == EMPTY)
		++numEdge;
	matrix[v1][v2] == wt;
}

void Graphm::delEdge(int v1, int v2) {
	if (matrix[v1][v2] != 0)
		--numEdge;
	matrix[v1][v2] = EMPTY;
}

#endif
