import sys
import os



class Graph:
    def __init__(self, v, directed=True):
        self.directed = directed
        self.nvertices = v
        self.nedges = v
        self.edges = [[0 for i in range(v)] for i in range(v)]
        self.degree = [0 for i in range(v)]

        


    def read_graph(self, filename):
        try:
            f = open(filename, 'r')
            data = f.readlines()
            #parse the data
            info = data[0]
            # the number of vertices in the graph
            self.nvertices = int(data[0].split()[0])
            n = int(data[0].split()[1]) # num of edges
            for i in range(1, n+1):
                x = int(data[i].split()[0])
                y = int(data[i].split()[1])
                self.insert_edge(x, y, self.directed)
    
        except IOError:
            print("Error reading in file")
            sys.exit()

    def insert_edge(self, x, y, directed):
        if x < self.nvertices:
            self.edges[x][y] = 1
            self.degree[x] += 1

        if directed != True:
            self.insert_edge(y, x, True)

    def print_graph(self):
        for edge in self.edges:
            for e in edge:
                print(e, " ", end="")
            print()

def main():
    g = Graph(10, False) 
    g.read_graph("graph.txt")
    g.print_graph()
if __name__ == "__main__":
    main()
    