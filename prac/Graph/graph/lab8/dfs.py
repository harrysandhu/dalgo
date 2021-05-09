from graph import Graph
MAXV = 100

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
        print("visiting vertex ", v)
        for w in adj(g, v):
            if discovered[w] == False:
                discovered[w] = True
                s.insert(0, w)

def main():
    g = Graph(10, False) 
    MAXV = 10
    g.read_graph("graph.txt")
    g.print_graph()
    # bfs(g, 2)
    dfs(g, 2)
if __name__ == "__main__":
    main()
    