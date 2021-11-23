#include<bits/stdc++.h>
using namespace std;

void getConnectedComponentsCount(int node, vector<int>& visited, vector<int> adjList[])
{
	visited[node] = 1;
	for(auto it: adjList[node])
	{
		if(visited[it] == 0)
			getConnectedComponentsCount(it, visited, adjList);
	}
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	
	vector<int> adjList[nodes+1];
	for(int i = 1; i <= edges; i++)
	{
		int u, v;
		cin >> u >> v;
		
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	
	vector<int> visited(nodes+1, 0);
	
	int count = 0;
	for(int i = 1; i <= nodes; i++)
	{
		if(visited[i] == 0){
			getConnectedComponentsCount(i, visited, adjList);
			count++;
		}
	}
	
	if(count == 1 && edges == nodes-1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
