#include "Graph.h"
#include <iostream>

Graph::Graph(bool d){
    directed = d;
    nvertices = 0; 
    nedges = 0;
    for(int i = 0; i <= MAXV; i++) degree[i] = 0;
}


void Graph::insert_edge(int x, int y, bool d){

    if(nedges > MAXOUTDEGREE) 
        cout << "Warning";
    
    edges[x][degree[x]] = y;
    degree[x] += 1;
    if(!d) insert_edge( y, x, true);
    else nedges++;
}

int* Graph::adj(int vertex){
    return edges[vertex];
}

void Graph::print_graph(void){
    for(int i = 0; i <= nvertices; i++){
        cout << i << " : ";
        for(int j = 0; j < degree[i]; j++){
            cout << edges[i][j] << " ";
        }   
        cout << "\n";
    }
}


void Graph::read_graph(void){
    int m;
    cin >> nvertices; //num of vertices
    cin >> m; //num of edges
    int x, y, d;
    //read in the edges
    for(int i = 0; i < m; i++){
        cin >> x;
        cin >> y;
        d = directed;
        insert_edge(x, y, d);
    }

}



