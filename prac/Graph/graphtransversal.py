"""Adjacency Lists in Matrices Graph"""
import sys
import os
import numpy as np


OUTDEGREE = 20
MAXV = 20



class Graph:
    def __init__(self, directed):
        self.directed = directed
        self.nvertices = 0
        self.nedges = 0
        self.edges = [[0 for i in range(OUTDEGREE)] for i in range(MAXV)]
        self.degree = [0 for i in range(MAXV)]

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
        if x < MAXV:
            #insert edge and update degree
            self.edges[x][self.degree[x]] = y
            self.degree[x] += 1 
            
            if directed != True:
                self.insert_edge(y, x, True)
            else:
                self.nedges += 1

    
    def print_graph(self):
        
        for i in range(MAXV):
            print(i, " -> ", end="")
            print(np.array(self.edges[i]))
        
    
    



def adj(g, x):
    return g.edges[x]


def dfs(g, i):
    discovered = [False for i in range(MAXV)]
    processed = [False for i in range(MAXV)]
    s = []
    discovered[i] = True
    s.insert(0, i)
    while len(s) != 0:
        v = s.pop(0)
        processed[v] = True
        print(v)
        for w in adj(g, v):
            if discovered[w] == False:
                discovered[w] = True
                s.insert(0, w)



def bfs(g, i):
    discovered = [False for i in range(MAXV)]
    processed = [False for i in range(MAXV)]
    q = []
    q.append(i)
    discovered[i] = True
    while len(q) != 0:
        v = q.pop(0)
        processed[v] = True
        print(v)
        for w in adj(g, v):
            if discovered[w] == False:
                discovered[w] = True
                q.append(w)
    
    

def main():
    g = Graph(False) 
    g.read_graph("graph.txt")
    g.print_graph()
    # bfs(g, 2)
    dfs(g, 2)
if __name__ == "__main__":
    main()
    