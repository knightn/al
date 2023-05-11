#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

// Implementation of Prim's algorithm
int primMST(vector<vector<pii>>& adjList) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int cost = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        cost += w;

        for (auto& v : adjList[u]) {
            if (!visited[v.first])
                pq.push(make_pair(v.second, v.first));
        }
    }

    return cost;
}

// Implementation of Kruskal's algorithm
struct Edge {
    int src, dest, weight;
};

bool edgeComp(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

int kruskalMST(vector<vector<pii>>& adjList) {
    int n = adjList.size();
    vector<Edge> edges;
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        for (auto& j : adjList[i])
            edges.push_back({i, j.first, j.second});
    }

    sort(edges.begin(), edges.end(), edgeComp);

    int cost = 0;

    for (auto& e : edges) {
        int u = e.src, v = e.dest, w = e.weight;

        int parentU = parent[u], parentV = parent[v];
        if (parentU != parentV) {
            cost += w;
            parent[parentV] = parentU;
        }
    }

    return cost;
}

// Example usage:
int main() {
    int n = 5;
    vector<vector<pii>> adjList(n);

    adjList[0].push_back(make_pair(1, 2));
    adjList[1].push_back(make_pair(0, 2));
    adjList[1].push_back(make_pair(2, 3));
    adjList[2].push_back(make_pair(1, 3));
    adjList[2].push_back(make_pair(3, 1));
    adjList[3].push_back(make_pair(2, 1));
    adjList[3].push_back(make_pair(4, 4));
    adjList[4].push_back(make_pair(3, 4));

    int primCost = primMST(adjList);
    int kruskalCost = kruskalMST(adjList);

    cout << "Cost of minimum spanning tree using Prim's algorithm: " << primCost << endl;
    cout << "Cost of minimum spanning tree using Kruskal's algorithm: " << kruskalCost << endl;

    return 0;
}
