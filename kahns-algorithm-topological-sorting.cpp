/*
Compute the in-degree of every node in the graph
Make a visited array of nodes and initialize the count of each node as 0 initially
First pick all the nodes with in-degree as 0 and push them into a queue
Repeat the following steps until the queue becomes empty
Start removing the nodes from the queue
Decrease the in-degree of all the nodes attached by this node by 1, if the in-degree of any of these attached nodes is 0, then push them into the queue
While pushing the node into the queue, increment the value of count by 1
Finally, check if the number of visited nodes is equal to the number of nodes in the graph, the graph does not contain a cycle, else it contains a cycle
Note: Indegree of a node is the total number of edges that are coming to that node.
*/
include<bits/stdc++.h>
using namespace std;

bool isCyclicGraph(vector<pair<int,int>>&edges,int n){
    vector<vector<int>> adj(n+1);
    vector<int> inDegree(n+1,0);
    for(auto it:edges){
        int u=it.first;
        int v=it.second;
        inDegree[v]++;
        adj[u].push_back(v);
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    int count=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        count++;
        for(auto nbr:adj[cur]){
            inDegree[nbr]--;
            if(inDegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(count==n)return false;
    return true;

}

int main(){
    vector<pair<int,int>> edges{{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    cout<<isCyclicGraph(edges,5);
	return 0;
}
