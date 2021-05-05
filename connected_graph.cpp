
/* https://blog.csdn.net/qq_41879343/article/details/104436388 */
/* https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/find-the-cycles */

/*input

5 4
1 2
3 4
5 4
3 5

ouput
1




*/

/* Therefore, in order to solve this problem we first identify all the connected components of the disconnected graph. For this, we use depth-first search 
 algorithm. For the DFS algorithm to work, it is required to maintain an array ‘found’ to keep an account of all the vertices that have been discovered 
 by the recursive function DFS. Once all the elements of a particular connected component are discovered (like vertices(9, 2, 15, 12) form a connected 
 graph component ), we check if all the vertices in the component are having the degree equal to two. If yes, we increase the
  counter variable ‘count’ which denotes the number of single-cycle-components found in the given graph. 
  To keep an account of the component we are presently dealing with, we may use a vector array ‘curr_graph’ as well.
  */


 // CPP program to find single cycle components
// in a graph.
#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

// degree of all the vertices
int degree[N];

// to keep track of all the vertices covered
// till now
bool found[N];

// all the vertices in a particular
// connected component of the graph
vector<int> curr_graph;

// adjacency list
vector<int> adj_list[N];

// depth-first traversal to identify all the
// nodes in a particular connected graph
// component
void DFS(int v)
{
	found[v] = true;
	curr_graph.push_back(v);
	for (int it : adj_list[v])
		if (!found[it])
			DFS(it);
}

// function to add an edge in the graph
void addEdge(vector<int> adj_list[N], int src,
			int dest)
{
	// for index decrement both src and dest.
	src--, dest--;
	adj_list[src].push_back(dest);
	adj_list[dest].push_back(src);
	degree[src]++;
	degree[dest]++;
}

int countSingleCycles(int n, int m)
{
	// count of cycle graph components
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (!found[i]) {
			curr_graph.clear();
			DFS(i);

			// traversing the nodes of the
			// current graph component
			int flag = 1;
			for (int v : curr_graph) {
				if (degree[v] == 2)
					continue;
				else {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				count++;
			}
		}
	}
	return(count);
}

int main()
{
	// n->number of vertices
	// m->number of edges
	int n = 15, m = 14;
	addEdge(adj_list, 1, 10);
	addEdge(adj_list, 1, 5);
	addEdge(adj_list, 5, 10);
	addEdge(adj_list, 2, 9);
	addEdge(adj_list, 9, 15);
	addEdge(adj_list, 2, 15);
	addEdge(adj_list, 2, 12);
	addEdge(adj_list, 12, 15);
	addEdge(adj_list, 13, 8);
	addEdge(adj_list, 6, 14);
	addEdge(adj_list, 14, 3);
	addEdge(adj_list, 3, 7);
	addEdge(adj_list, 7, 11);
	addEdge(adj_list, 11, 6);

	cout << countSingleCycles(n, m);

	return 0;
}
