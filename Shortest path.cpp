#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Define a structure to represent a graph edge
struct Edge {
    int dest;
    int weight;
};

// Define a structure to represent a graph node
struct Node {
    vector<Edge> edges;
};

// Function to find the shortest path using Dijkstra's algorithm
vector<int> dijkstra(const vector<Node>& graph, int source) {
    int n = graph.size(); // Number of nodes
    vector<int> dist(n, INF); // Initialize distances to infinity
    dist[source] = 0; // Distance from source to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // Push the source node with distance 0

    while (!pq.empty()) {
        int u = pq.top().second; // Extract the node with the minimum distance
        pq.pop();

        // Iterate over the neighbors of the current node
        for (const Edge& edge : graph[u].edges) {
            int v = edge.dest;
            int weight = edge.weight;

            // Relaxation step: Update the distance if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Push the updated distance and node to the priority queue
            }
        }
    }

    return dist;
}

int main() {
    // User input for number of nodes and edges
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<Node> graph(numNodes);

    // User input for each edge: source, destination, and weight
    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < numEdges; ++i) {
        int source, dest, weight;
        cin >> source >> dest >> weight;
        graph[source].edges.push_back({dest, weight});
    }

    int source; // Source node for shortest path calculation
    cout << "Enter the source node: ";
    cin >> source;

    vector<int> shortestDistances = dijkstra(graph, source);

    // Output shortest distances from source to all other nodes
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}

