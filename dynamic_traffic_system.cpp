#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

// Define a structure for graph edges
struct Edge {
    int dest;
    int weight;
};

// Define the Graph class
class Graph {
public:
    unordered_map<int, vector<Edge>> adjList;

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight}); // Assuming an undirected graph
    }

    vector<int> dijkstra(int start, int n) {
        vector<int> dist(n, numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto &neighbor : adjList[node]) {
                int newDist = currDist + neighbor.weight;
                if (newDist < dist[neighbor.dest]) {
                    dist[neighbor.dest] = newDist;
                    pq.push({newDist, neighbor.dest});
                }
            }
        }
        return dist;
    }
};

int main() {
    Graph cityGraph;
    int nodes, edges;
    
    cout << "Enter number of intersections (nodes) and roads (edges): ";
    cin >> nodes >> edges;
    
    cout << "Enter edges in the format: src dest weight (road time in minutes):\n";
    for (int i = 0; i < edges; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        cityGraph.addEdge(src, dest, weight);
    }
    
    int start;
    cout << "Enter starting intersection: ";
    cin >> start;
    
    vector<int> shortestPaths = cityGraph.dijkstra(start, nodes);
    
    cout << "\nShortest travel time from intersection " << start << " to other intersections:\n";
    for (int i = 0; i < nodes; ++i) {
        if (shortestPaths[i] == numeric_limits<int>::max())
            cout << "Intersection " << i << " is unreachable.\n";
        else
            cout << "To intersection " << i << " : " << shortestPaths[i] << " minutes\n";
    }
    
    return 0;
}
