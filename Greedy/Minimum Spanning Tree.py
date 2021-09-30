""" Given a weighted, undirected and connected graph. 
The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Input:
The first line of input contains an integer T denoting the number of testcases. 
Then T test cases follow. The first line of each testcase contains two integers V (starting from 1), 
E denoting the number of nodes and number of edges. Then in the next line are 3*E space separated 
values a b w where a, b denotes an edge from a to b and w is the weight of the edge.

Output:
For each test case in a new line print the sum of weights of  the edges of the Minimum Spanning Tree 
formed of the graph.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete 
the function  spanningTree() which takes number of vertices V and the number of edges E and a 
graph graph as inputs and returns an integer denoting the sum of weights of the edges of the 
Minimum Spanning Tree.

Note: Please note that input of graph is 1-based but the adjacency matrix is 0-based.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= V <= 1000
V-1 <= E <= (V*(V-1))/2
1 <= a, b <= N
1 <= w <= 1000
Graph is connected and doesn't contain self loops & multiple edges.

Example:
Input:
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5

Output:
4
5

Example:
Testcase 1:  Sum of weights of edges in the minimum spanning tree is 4. """