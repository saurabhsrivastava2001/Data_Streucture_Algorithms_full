// Chemical Reaction Pathways
// Problem Statement:
// In a research lab, chemical compounds are nodes and reactions are edges. Scientists want to discover all possible reaction paths starting from a base compound.
// Use DFS to find all possible paths or cycles in the reaction network
#include <iostream>
using namespace std;

void dfs(int node, bool visited[], int graph[][5], int n) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, visited, graph, n);
        }
    }
    if (node == 0) {
        cout << "Cycle detected at node " << node << endl;
    }
    else {
        cout << "Path from node " << node << " to node 0" << endl;
    }
}
int main(){
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    bool visited[5] = {false};
    int n = 5;
    cout << "DFS starting from node 0: ";
    dfs(0, visited, graph, n);
    cout << endl;
}