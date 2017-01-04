#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define VISITED -1
#define INFINITY 99999
#define UNVISITED -3

/* 未完成
void Dijkstra(Graph* G, int* D, int s) {
	int i,v,w;
	DijkElem temp;
	DijkElem E[];
	temp.distance = 0;
	temp.vertex = s;
	E[0] = temp;
	Heap<DijkElem, DDComp> H(E, 1, G->e());   //DDComp待实现
	for (int i = 0; i < G->n(); ++i) {
		do {
			if (H.size() == 0)
				return;
			temp = H.removefirst();
			v = temp.vertex;
		} while (G->getMark(v) == VISITED);
		G->setMark(v, VISITED);
		if (D[v] == INFINITY)
			return;
		for (w = G->first(v); w<G->n(); w = G->next(v, w))
			if (D[w] > (D[v] + G->weight(v, w))) {
				D[w] = D[v] + G->weight(v, w);
				temp.distance = D[w];
				H.insert(temp);
			}
	}
}

*/

int minVertex(Graph* G, int* D, int* mark);

void Dijkstra(Graph* G, int* D, int s) {
	int v,w;
	int* mark = new int[G->n()];
	for (int i = 0; i < G->n(); ++i)
		mark[i] = UNVISITED;
	for (int i = 0; i < G->n(); ++i)
		D[i] = G->weight(s, i);
	mark[s] = VISITED;

	for (int i = 0; i < G->n(); ++i) {
		v = minVertex(G, D, mark);
		if (D[v] == INFINITY || v == -1)
			return;
		mark[v] = VISITED;
		for (w = G->first(v); w < G->n(); w = G->next(v, w))
			if (D[w] > (D[v] + G->weight(v, w)))
				D[w] = D[v] + G->weight(v, w);
	}
}

int minVertex(Graph* G, int* D, int* mark) {
	int i, v = -1;
	for (i = 0; i < G->n(); ++i)
		if (mark[i] == UNVISITED) {
			v = i;
			break;
		}
	for (++i; i < G->n(); ++i)
		if ((mark[i] == UNVISITED) && (D[i] < D[v]))
			v = i;
	return v;
}

#endif
