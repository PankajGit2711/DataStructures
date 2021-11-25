bool bfsCycleDetection(int start, int V, vector<int> adj[], vector<int>& visited)
{
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, -1});

    while(!q.empty())
    {
        int currNode = q.front().first;
        int parentNode = q.front().second;
        q.pop();

        for(auto it: adj[currNode])
        {
            if(visited[it] == 0)
            {
                visited[it] = true;
                q.push({it, currNode});
            }
            else if(parentNode != it)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);

    for(int i = 0; i < V; i++)
    {
        if(visited[i] == 0)
            if(bfsCycleDetection(i, V, adj, visited))
                return true;
    }
    return false;
}
