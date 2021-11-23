//Solution to Bishu and His Girlfriend Hackerearth Problem
#include<bits/stdc++.h>
using namespace std;

void SingleSourceShortestPath(int node, int dist, vector<int>& visited, vector<int> adjList[], vector<int> distance)
{
    visited[node] = 1;
    distance[node] = dist;
    
    for(auto it: adjList[node])
    {
        if(visited[it] == 0)
            SingleSourceShortestPath(it, distance[node] + 1, visited, adjList, distance);
    }
}

int main()
{
    int nodes;
    cin >> nodes;
    
    vector<int> adjList[nodes+1];
    
    for(int i = 1; i <= nodes-1; i++)
    {
        int u, v;
        cin >> u >> v;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<int> visited(nodes+1, 0);
    vector<int> distance(nodes+1);
    
    SingleSourceShortestPath(1, 0, visited, adjList, distance);
    
    int girls;
    cin >> girls;
    
    int out = 0, minDist = INT_MAX;
    
    while(girls--)
    {
        int girlsCity;
        cin >> girlsCity;
        
        if(distance[girlsCity] < minDist){
            minDist = distance[girlsCity];
            out = girlsCity;
        }
        else if(distance[girlsCity] == minDist && girlsCity < out)
            out = girlsCity;
    }
    cout << out << endl;
}
