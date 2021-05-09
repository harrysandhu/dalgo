- Dynamic Programming
    - general, powerful
    - alg design technique
    - optimization problems
    - shortest path, min, max, exhaustive search (clever way)
    * DP -> careful brute force
    
    - Problems
        - fib
        - shortest paths

 


- dynamic
    - memo + recursion + guessing
    + floyd-warshall
    - knapsack
    - msp
    + tsp
    - ford-fulkerson
    - change
    

- pathfinding
    + Dijstra : single source shortest 
    + A*

- greedy
    + prim
    + kruskal



ALGORITHM get_min_move(G, x, y)
    min = G[x-1][y]
    minx = 0
    miny = 0
    for i = x-1 to x+1 do
        for j = y to y+1 do
            if G[i][j] != null do
                if G[i][j] < min do
                    min = G[i][j]
                    minx = i
                    miny = j
    return (minx, miny)

ALGORITHM MinimalRoute(G):
    // Input graph G, matrix representaion
    // Output array R, representing the minimal weighted route

    R = []
    y = 0 // y coordinate starting from 0
    x = 0 //  x coordinate starting from 0
    start = G[0][0]
    for i = 0 to n - 1 do
        if G[0][i] < start 
            start = G[0][i]
            x = i
    
    // find the minimum value in available moves
    while y < n-1 do
        minx, miny = get_min_move(G, x, y)
        R.add([minx, miny])

    return R




