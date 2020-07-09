#include <iostream>
#include "Graph.h"

using namespace std;


int main(void){
    Graph g(false);
    g.read_graph();
    g.print_graph();
}