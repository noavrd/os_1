#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <climits>

using namespace std;

#define V 5

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}

bool isValidGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] < 0) {
                cout << "Error: Graph contains negative weights." << endl;
                return false;
            }
        }
    }
    return true;
}

int main() {
    int graph[V][V];
    cout << "Enter the graph as an adjacency matrix (each row on a new line):" << endl;

    // Input graph from standard input
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (!(cin >> graph[i][j])) {
                cout << "Error: Invalid input format. Ensure all values are integers." << endl;
                return 1;
            }
        }
    }

    if (!isValidGraph(graph)) {
        return 1;
    }

    // Function call
    dijkstra(graph, 0);

    return 0;
}