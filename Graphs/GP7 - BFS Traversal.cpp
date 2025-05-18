/*
GP7 - Breadth First Search Traversal in a Graph

Time Complexity = O(V) + O(2E) = O(V + 2E) = O(V + E) // Runs for all nodes and for each node it will run for all of it's degrees which is 2 * Edges for a node.
Space Complexity = O(3N) = O(N) // Queue + Visited Array + Adjacency List

Tested with the following input gives following output
Input: Nodes = 9, Edges = 9, EdgesList = {[1, 2], [1, 6], [2, 3], [2, 4], [6, 7], [6, 9], [4, 5], [7, 8], [5, 8]}
Output: 1 -> 2 -> 6 -> 3 -> 4 -> 7 -> 9 -> 5 -> 8  
*/ 


#include <bits/stdc++.h>

using namespace std;

vector<int> traverseBFS(int nodes, vector<int> adjList[])
{
    vector<int> out;
    vector<int> visited(nodes + 1, false); // Initialised the visited array with all nodes value as false

    // Created the initial config. where created and initialised the queue and added first node inside it. Also made visited of first node as true.
    queue<int> q;
    q.push(1); // Add the first node inside queue.
    visited[1] = true; // As soon as the node goes inside queue mark it as visited.

    // Untill queue is empty run the following process.
    while(!q.empty())
    {
        // Take out the front element from the queue which will also be our current node.
        int currentNode = q.front();
        q.pop();

        out.push_back(currentNode); // Add it into the resultant array.

        // Ask the current node who's your neighbour. For each of it's neighbour do the following process.
        for(auto& neighbour: adjList[currentNode])
        {
            // If the neighbour is already visited skip it. If not then.
            if(visited[neighbour] == false)
            {
                q.push(neighbour); // Add the neighbour in the queue.
                visited[neighbour] = true; // As soon as the neighbour node goes inside queue mark it as visited.
            }
        }
    }
    return out;
}

vector<int> printBFSTraversal(int nodes, int edges, vector<vector<int>>& edgesList)
{
    // Creating adjacency list from the given graph's edgelist.
    vector<int> adjList[nodes + 1];

    for(auto& edge: edgesList)
    {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> out = traverseBFS(nodes, adjList);
    return out;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges in the graph: " << endl;
    cin >> nodes >> edges;

    vector<vector<int>> edgesList;
    cout << "Enter the individual nodes in between which you want to create an edge: " << endl;
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        edgesList.push_back({u, v});   
    }

    vector<int> out = printBFSTraversal(nodes, edges, edgesList);

    for(auto& node: out)
        cout << node << " -> "; 

    return 0;
}