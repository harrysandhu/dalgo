#include "Graph.h"
#include <iostream>
#include <queue>
#include <algoritm>

using namespace std;


/*
*/

void bfs(Graph &g, int start){
    queue<int> q; // push pop
    bool discovered[MAXV];
    bool processed[MAXV];
    discovered[start] = true;
    q.push(start);
    while(q.size() > 0){
        int v = q.pop();
        //if v goal....
        processed[v] = true;

    }
 
}



int main(void){
    Graph g(true);
    g.read_graph();
    g.print_graph();

    bfs(g);

}

