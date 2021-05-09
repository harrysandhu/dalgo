import numpy as np
class Graph:
    def __init__(self, numv, directed):
        self.nvertices = numv
        self.edges = [[0 for _ in range(numv)] for _ in range(numv)]
        self.degree = [0 for _ in range(numv)]
        self.directed = directed


    def read_graph(self, filename):
        lines = []
        with open(filename, "r") as f:
            lines = f.readlines()
        f.close()
        for line in lines:
            x = int(line.split(" ")[0])
            y = int(line.split(" ")[1])
            assert (x < self.nvertices and y < self.nvertices), \
            f"Edge value cannot exceed given v={self.nvertices}" 
            self.insert_edge(x, y, self.directed)


    def insert_edge(self, x, y, directed):
        self.edges[x][y] = 1
        self.degree[x] += 1
        if directed != True:
            self.insert_edge(y, x, True)

    def adjacent(self, v):
        return [i for i in range(len(self.edges[v])) if self.edges[v][i] != 0]

    def bfs(self, s):
        discovered = [False for _ in range(self.nvertices)] 
        q = []
        # set source as discovered initially
        q.append(s)
        discovered[s] = True 
        print(q)
        # loop while everything is processed, i.e everything goes in and out of 
        # the q.
        while len(q) != 0:
            
            v = q.pop(0) 
            # process if not seen
            if discovered[v] == False:
                discovered[v] = True
            
            # add unseen children
            for w in self.adjacent(v):
                if discovered[w] == False:
                    discovered[w] = True
                    q.append(w)



    def dfs(self, s):
        discovered = [False for _ in range(self.nvertices)] 
        stack = [] 
        stack.insert(0, s)
        discovered[s] = True
        v = stack[0]
        while len(stack) != 0:            
            print(stack)
            # process if not seen
            if discovered[v] == False:
                discovered[v] = True
        
            # add unseen children
            for w in self.adjacent(v):
                if discovered[w] == False:
                    stack.insert(0, w)
                    print(stack)
                    discovered[w] = True
            v = stack.pop(0) 

if __name__ == "__main__":
    g = Graph(numv=8, directed=False)
    g.read_graph("graph.txt")
    print(np.array(g.edges))    
    g.dfs(1)




ALGORITHM DegThree(G)
    // Input G a n x m matrix 
    for u <- 0 to n do
        for v <-0 to m do
            if G[u][v] == 3 do
                return True
    
    return False