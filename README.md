# Shortest-Path
Shortest Path through all node in a graph using C++

Problem: 
  Given undirected path (V,E), pair of vertices (X, Y). Find the shortest path starting from X, travelling through all the nodes in the graph, ending at Y.

The Floyd - Warshall is used to minimize the weight matrix, ensure that with any two nodes, a[i][j] saves the shortest distance from i to j and its specific path. Besides, it helps lowering the number of Backtracking steps.   

We test with two programs, Floyd Warshall combined with Backtracking and only Backtracking. The algorithm using Floyd Warshall allows going back to the same path between two nodes as much as possible while latter only go through a node one time.

Input:
  First line contains the number of edges (m), vertices (n) of the graph and pair of vertices (X,Y)
  The next m lines contains 3 index i, j, k while k is the distance between vertex i and j.
 Output:
  The first line contains the path from X to Y
  The second line contains the distance of that path

