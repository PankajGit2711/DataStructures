void dfsToClone(Node* curr, Node* node, vector<Node*>& visited)
{
    //curr -> Currently iterating Node of the exisiting graph which is to be copied.
    //node -> New Node which is a copy of the curr Node.

    visited[node -> val] = node; // Marked the new node as visited in visited array by filling it's value.
    for(auto it: curr -> neighbors) // Iterate over all neighbors of the curr node (Node of existing graph which is to be copied)
    {
        if(visited[it -> val] == NULL) // if the node is not visited
        {
            Node* newNode = new Node(it -> val); // Create a clone of the node.
            (node -> neighbors).push_back(newNode); // Push the new node in the adjList(neighbors) of the start node
            dfsToClone(it, newNode, visited); // Call dfs to repeat this process for further nodes.
        }
        else
            (node -> neighbors).push_back(visited[it -> val]);
    }
}



Node* cloneGraph(Node* node) {
    if(node == NULL)
        return NULL;

    vector<Node*> visited(1000, NULL); // Created visited array of Node type.
    Node* start = new Node(node -> val); // Created the start node (copy of first node) with the value of given node in input.
    visited[node -> val] = start; // Marked the node as visited in visited array by filling it's value instead of 0 and 1.

    // Iterate over all neighbors of the current node i.e. DFS
    for(auto it: node -> neighbors)
    {
        if(visited[it -> val] == NULL) // if the node is not visited
        {
            Node* newNode = new Node(it -> val); // Create a clone of the node.
            (start -> neighbors).push_back(newNode); // Push the new node in the adjList(neighbors) of the start node
            dfsToClone(it, newNode, visited); // Call dfs to repeat this process for further nodes.
        }
        else
            (start -> neighbors).push_back(visited[it -> val]);
    }
    return start; // Return the starting node.
}
