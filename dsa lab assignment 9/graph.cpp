
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Edge structure
struct Edge {
    int u, v, weight;
};

// Disjoint Set Union for Kruskal
class DSU {
    vector<int> parent, rankValue;

public:
    DSU(int n) {
        parent.resize(n);
        rankValue.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (rankValue[a] < rankValue[b])
            swap(a, b);

        parent[b] = a;

        if (rankValue[a] == rankValue[b])
            rankValue[a]++;

        return true;
    }
};

class Graph {
    int V;

    // Adjacency list: {neighbour, weight}
    vector<vector<pair<int, int>>> adj;

    vector<Edge> edges;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add an undirected weighted edge
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        edges.push_back({u, v, w});
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (auto neighbour : adj[u]) {
                int v = neighbour.first;

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    // DFS recursive helper
    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto neighbour : adj[u]) {
            int v = neighbour.first;

            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    // DFS
    void DFS(int start) {
        vector<bool> visited(V, false);

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);

        cout << endl;
    }

    // Kruskal's Minimum Spanning Tree
    void Kruskal() {
        vector<Edge> sortedEdges = edges;

        sort(sortedEdges.begin(), sortedEdges.end(),
             [](Edge a, Edge b) {
                 return a.weight < b.weight;
             });

        DSU dsu(V);

        int totalWeight = 0;
        int count = 0;

        cout << "\nKruskal's MST:\n";

        for (auto e : sortedEdges) {
            if (dsu.unite(e.u, e.v)) {
                cout << e.u << " - " << e.v
                     << " : " << e.weight << endl;

                totalWeight += e.weight;
                count++;

                if (count == V - 1)
                    break;
            }
        }

        if (count != V - 1) {
            cout << "MST does not exist. Graph is disconnected.\n";
        } else {
            cout << "Total MST Weight: " << totalWeight << endl;
        }
    }

    // Prim's Minimum Spanning Tree
    void Prim(int start = 0) {
        vector<bool> inMST(V, false);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, start});

        int totalWeight = 0;
        int count = 0;

        cout << "\nPrim's MST:\n";

        while (!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;
            totalWeight += weight;
            count++;

            if (u != start)
                cout << "Vertex " << u
                     << " added with weight " << weight << endl;

            for (auto neighbour : adj[u]) {
                int v = neighbour.first;
                int w = neighbour.second;

                if (!inMST[v])
                    pq.push({w, v});
            }
        }

        if (count != V) {
            cout << "MST does not exist. Graph is disconnected.\n";
        } else {
            cout << "Total MST Weight: " << totalWeight << endl;
        }
    }

    // Dijkstra's Shortest Path Algorithm
    void Dijkstra(int source) {
        vector<int> dist(V, INF);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int distance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (distance != dist[u])
                continue;

            for (auto neighbour : adj[u]) {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (dist[u] <= INF - weight &&
                    dist[u] + weight < dist[v]) {

                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nDijkstra's Shortest Paths from "
             << source << ":\n";

        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";

            if (dist[i] == INF)
                cout << "Unreachable";
            else
                cout << dist[i];

            cout << endl;
        }
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g.addEdge(u, v, w);
    }

    int choice, start;

    do {
        cout << "\n===== GRAPH ALGORITHMS =====\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. Kruskal MST\n";
        cout << "4. Prim MST\n";
        cout << "5. Dijkstra Shortest Path\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.BFS(start);
                break;

            case 2:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.DFS(start);
                break;

            case 3:
                g.Kruskal();
                break;

            case 4:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.Prim(start);
                break;

            case 5:
                cout << "Enter source vertex: ";
                cin >> start;
                g.Dijkstra(start);
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
