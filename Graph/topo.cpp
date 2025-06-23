void topoSort(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
        for (int j : adj[i]) inDegree[j]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int nbr : adj[node]) {
            if (--inDegree[nbr] == 0) q.push(nbr);
        }
    }
}