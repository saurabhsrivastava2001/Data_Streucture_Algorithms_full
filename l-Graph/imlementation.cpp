//implementation of the directed graph by 2d array
#include <iostream>
#include <iomanip>
using namespace std;
//dfs
void dfs(int adj[10][10], int visited[], int start, int vertices){
    visited[start] = 1; // mark the current node as visited
     // print the current node
    for (int i = 0; i < vertices; i++){
        if (adj[start][i] == 1 && !visited[i]){ // check if there is an edge and the node is not visited
            dfs(adj, visited, i, vertices); // recursive call to visit the next node
        }
    }cout << start + 1 << " ";
}

int main(){
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices; // input number of vertices
    cout << "Enter the number of edges: ";
    cin >> edges; // input number of edges
    int adj[10][10] = {0}; // adjacency matrix initialized to 0
    for (int i = 0; i < edges; i++){
        int u, v;
         cout << "Enter edge (u v): ";
        cin >> u >> v; // input edge
        adj[u - 1][v - 1] = 1; // mark the edge in the adjacency matrix
    }
    int visited[10] = {0}; // visited array initialized to
    cout << "DFS Traversal: ";
    dfs(adj, visited, 0, vertices); // start DFS from vertex 0
    cout << endl;
    return 0;
    
}