#ifndef GRAPHTRAVERSE_H
#define GRAPHTRAVERSE_H

#define UNVISITED 1
#define VISITED 0

#include "Graphm.h"


class GraphTraverse {
public:
	GraphTraverse(Graphm& g);
	void dfs(int vertex);
	void bfs(int vertex);

private:
	bool* mark;
	int numVertex;
	Graphm& graph;

	void setMark(int v) { mark[v] = VISITED; }
	bool getMark(int v) { return mark[v]; }

	void previsit();
	void postvisit(int v);
	
};

GraphTraverse::GraphTraverse(Graphm& g) {
	numVertex = g.n();
	graph = g;
	mark = new bool[numVertex];
	for (int i = 0; i < numVertex; ++i)
		mark[i] = UNVISITED;

}

void GraphTraverse::dfs(int v) {
	Stack<int> stack(numVertex);
	stack.push(v);
	int vertex = v;
	while (true) {
		vertex = stack.last();
		for (int i = graph.first(vertex); i < numVertex; i = graph.next(vertex, i))
			if (graph.getMark[i] == UNVISITED)
				stack.push(i);
		if (graph.first(vertex) == numVertex)
			break;
	}
	//do something
}

void GraphTraverse::bfs(int v) {
	Queue<int> queue(numVertex);
	queue.enqueue(v);
	int vertex = v;
	while () {
		vertex = queue.first;
		for (int i = graph.first(vertex); i < numVertex; i = graph.next(vertex, i))
			if (graph.getMark[i] == UNVISITED)
				queue.enqueue(i);
		if (graph.first(vertex) == numVertex)
			break;
	}
	//do something
}

void GraphTraverse::previsit() {

}

void GraphTraverse::postvisit() {

}
#endif
