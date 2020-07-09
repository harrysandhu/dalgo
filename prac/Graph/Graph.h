/* Implementation of graph and elementary graph algorithms */
#include <iostream>
#define MAXV 100
#define MAXOUTDEGREE 50

using namespace std;


class Graph{
private:
    int nvertices;
    int nedges;
    bool directed;
public:
    Graph(bool directed); //initializes graph
    void read_graph(void);  // reads tuples of edges of the graph from stdi
    void insert_edge(int x, int y, bool d);
    void print_graph(void);
    int edges[MAXV + 1][MAXOUTDEGREE];
    int* adj(int vertex);
    int degree[MAXV + 1]; 
};