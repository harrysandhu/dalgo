import sys
import os

OUTDEGREE = 100
MAXV = 50


class Graph:
    def __init__(self, directed):
        self.directed = directed
        self.nvertices = 0
        self.nedges = 0
        self.edges = [[0 for x in range(MAXV + 1)] for y in range(OUTDEGREE)]
        self.degree = [0 for x in range(MAXV + 1)]

    def read_graph(self, filename):
        try:
            f = open(filename, "r")
            data = f.readlines()
            s = data[0]
            # read the first line
            self.nvertices = int(s.split()[0])
            m = int(s.split()[1])
            
            #read next lines
            for i in range(1, m+1):
                # print(int(data[i].split()[0]))
                x, y = int(data[i].split()[0]), int(data[i].split()[1])
                self.insert_edge(x, y, self.directed)

        except IOError:
            print("Input error")
            sys.exit()

    # int x, int y, bool d
    def insert_edge(self, x, y, d):
        self.edges[x][self.degree[x]] = y
        self.degree[x] += 1

        if d != True:
            self.insert_edge(y, x, True)
        else:
            self.nedges += 1

        
    def print_graph(self):
        for i in range(self.nvertices+1):
            print(i," : ", end="")
            print(self.adj(i))
            # for x in range(self.degree[i]):
                # print(self.edges[i][x],"",end="")
            
            print("")

    def adj(self, vertex):
        return self.edges[vertex][:self.degree[vertex]]
        

def bfs(graph, start):
    q = []
    discovered = [False for x in range(MAXV+1)]
    processed = [False for x in range(MAXV+1)]
    q.append(start)
    discovered[start] = True
    print(graph.adj(start))
    while len(q) > 0:
        v = q.pop(0)
        print(v)
        print(q)
        discovered[v] = True
        processed[v] = True
        for w in graph.adj(v):
            if discovered[w] == False:
                q.append(w)



def dfs(graph, start):
    s = []
    discovered = [False for x in range(MAXV + 1)]     
    processed = [False for x in range(MAXV + 1)]
    # discovered[start] = True
    s.insert(0, start)
    while len(s) >0:
        v = s.pop(0)
        print(v)
        print(s)
        if discovered[v] != True:
            discovered[v] = True
            for w in graph.adj(v):
                s.insert(0, w)



def dfsr(graph, start, d_ar):
    print(start)
    d_ar[start] = True
    for w in graph.adj(start):
        if d_ar[w] != True:
            d_ar[w] = True
            dfsr(graph, w, d_ar)

    print(d_ar)


def main():
    #read in the graph
    g = Graph(False)
    g.read_graph(sys.argv[1])
    
    # g.print_graph()

    bfs(g, 2)
    print("\n\n\n")
    dfs(g, 2)
    d_ar = [False for x in range(7)]     
    print("\n\n\n")

    dfsr(g, 2, d_ar)
if __name__ == "__main__":
    main()



    