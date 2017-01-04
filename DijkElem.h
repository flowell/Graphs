#ifndef DIJKELEM_H
#define DIJKELEM_H

#define EMPTY -1;
#define INFINITY 99999;

class DijkElem {
public:
	int vertex, distance;
	DijkElem() { vertex = EMPTY; distance = INFINITY; } 
	DijkElem(int v, int d) { vertex = v; distance = d; }
};

#endif
