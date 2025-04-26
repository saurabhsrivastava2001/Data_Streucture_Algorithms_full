//warshall algorithms
// This code implements the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices in a weighted graph.
// The graph is represented as an adjacency matrix, where graph[i][j] is the weight of the edge from vertex i to vertex j.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to implement the Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    // Initialize the distance matrix with the input graph
    vector<vector<int>> dist = graph;

    // Update the distance matrix using the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
