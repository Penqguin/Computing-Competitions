#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Struct to represent an edge in the graph
struct Edge {
    int x, y, cost;      // Vertices x and y, and cost cost of the edge
    bool original;    // Indicates if the edge is part of the original graph
    Edge(int x, int y, int cost, bool original) : x(x), y(y), cost(cost), original(original) {}
};

// Operator overload for sorting edges
bool operator<(const Edge& a, const Edge& b) {
    // Compare edges first by cost; if weights are equal, prioritize original edges
    if (a.cost != b.cost) return a.cost < b.cost;
    return a.original && !b.original;
}

// Union-Find (Disjoint Set Union) class for managing connected components
class UnionFind {
private:
    vector<int> parent; // Array to track the parent of each node
    vector<int> rank;   // Array to track the rank (depth) of trees

public:
    // Constructor to initialize the Union-Find structure
    UnionFind(int size) : parent(size + 1), rank(size + 1, 1) {
        // Each node is its own parent initially
        for (int i = 1; i <= size; i++) parent[i] = i;
    }

    // Find the root of the node x with path compression
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x]; // Return the root
    }

    // Union of two sets containing x and y
    void unite(int x, int y) {
        int rx = find(x), ry = find(y); // Find roots
        if (rx == ry) return; // Already in the same set
        // Union by rank
        if (rank[rx] < rank[ry]) swap(rx, ry); // Ensure rx is the deeper tree
        parent[ry] = rx; // Link ry to rx
        if (rank[rx] == rank[ry]) rank[rx]++; // Increment rank if necessary
    }

    
    void reset(int size) {
        parent.resize(size + 1);
        rank.resize(size + 1, 1);
        for (int i = 1; i <= size; i++) parent[i] = i;
    }
};

int main() {
    int n, m, d; // n: number of nodes, m: number of edges, d: enhancer strength
    cin >> n >> m >> d;
    
    vector<Edge> edges; // Vector to store all edges
    for (int i = 0; i < m; i++) {
        int x, y, cost; // Variables to store edge endpoints and cost
        cin >> x >> y >> cost;
        edges.push_back(Edge(x, y, cost, i < n - 1)); // Store edge, marking original if it's among the first n-1 edges
    }
    
    // Sort edges based on cost (and original status)
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n); // Create Union-Find structure for n nodes
    int days = 0; // Variable to count additional days needed
    int connected = 0; // Counter for connected components
    Edge maxEdge(-1, -1, -1, false); // Variable to store the maximum cost edge used in MST
    
    // Process edges to construct the Minimum Spanning Tree (MST)
    for (int i = 0; i < edges.size(); i++) {
        const Edge& e = edges[i];
        if (connected >= n - 1) break; // If already connected, exit loop
        if (uf.find(e.x) != uf.find(e.y)) { // Check if x and y are in different components
            uf.unite(e.x, e.y); // Union the components
            if (!e.original) days++; // Increment days if the edge is not original
            maxEdge = e; // Update the max edge
            connected++; // Increase the count of connected edges
        }
    }

    // Calculate the weight of the heaviest edge (wl)
    int wl = maxEdge.cost;

    // Reset the Union-Find structure and process edges again
    uf.reset(n);
    for (const Edge& e : edges) {
        // Ensure we only process edges that could replace the max edge
        if (uf.find(e.x) != uf.find(e.y)) {
            if (e.cost < wl || (e.cost == wl && e.original)) {
                uf.unite(e.x, e.y); // Union if this edge is better
            } else if (e.original && e.cost <= d) {
                days -= 1;
                break;
            }
        }
    }
    
    // Output the total days needed
    cout << days; // Output the total days needed
    return 0;
}
