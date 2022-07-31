/*********************************************************************************************

Recursion - 35:- M Coloring Problem Graph

Time Complexity:- O(n^m); For N nodes we are trying all M colors.
Space Complexity:- O(n) + O(n); For Auxiliary Stack Space and Color array.

*********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool isPossibleColoring(int index, int n, int node, vector<int> graph[], vector<int>& colors)
{
    for(auto &neighbour: graph[node])
    {
        if(colors[neighbour] == index)
            return false;
    }
    return true;
}

bool graphColoringHelper(int node, int m, int n, vector<int> graph[], vector<int>& colors)
{
    if(node == n)
        return true;
        
    for(int i = 1; i <= m; i++)
    {
        if(isPossibleColoring(i, n, node, graph, colors) == true)
        {
            colors[node] = i;
            if(graphColoringHelper(node + 1, m, n, graph, colors) == true)
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<int> graph[], int m, int n) {
    vector<int> colors(n, 0);
    
    if(graphColoringHelper(0, m, n, graph, colors) == true)
        return true;
    return false;
}


int main()
{
    int colors;
    cin >> colors;
    int nodes, edges;
    cin >> nodes >> edges;
    
    vector<int> graph[nodes+1];
    
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << graphColoring(graph, colors, nodes) << endl;
    return 0;
}