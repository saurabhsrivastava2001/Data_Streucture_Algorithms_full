

#include <iostream>
using namespace std;

// Depth First Search (DFS) function
void  dfs (int adj[10][10], int visited[] ,int start,int vertices,int currupt){
    if (currupt==start){
        cout<<"found to be mentainence"<<currupt;
        return;
    }
    visited[start]=1;
    for (int i=0;i<vertices;i++)
    {
        if (adj[start][i]==1 && visited[i]!=1){
            dfs(adj,visited,i,vertices,currupt);
        }
    }
    cout<<"at the room"<<

}


int main(){
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices; // input number of vertices
    cout << "Enter the number of edges: ";
    cin >> edges; // input number of edges 
    int adj[10][10] = {0}; // adjacency matrix initialized to 0
    for (int i=0;i<edges;i++){
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v; // input edge
        adj[u-1][v-1] = 1; // mark the edge in the adjacency matrix
    }
    int visited[10] = {0}; // visited array initialized to 0
    int currupt=5;
    cout << "DFS Traversal: ";
    dfs(adj, visited, 0, vertices,currupt); // start DFS from vertex 0
    cout << endl;
    return 0;
}