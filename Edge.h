#ifndef EDGE_H
#define EDGE_H

#define EMPTY -1
class Edge {
	int vert, wt;
public:
	Edge();
	Edge(int v, int w);
	int vertex();
	int weight();
};
Edge::Edge() {
	vert = EMPTY;
	wt = EMPTY;
}
Edge::Edge(int v, int w) {
	vert = v;
	wt = w;
}
int Edge::vertex() {
	return vert;
}
int Edge::weight() {
	return wt;
}
#endif
