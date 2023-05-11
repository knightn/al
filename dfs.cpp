#include <iostream>
#include <vector>

using namespace std;

void dfsUtil(vector<vector<int>>& adjList, vector<bool>& visited, int currVertex) {
    visited[currVertex] = true;
    cout << currVertex << " ";

    for (int neighbor : adjList[currVertex]) {
        if (!visited[neighbor]) {
            dfsUtil(adjList, visited, neighbor);
        }
    }
}

void dfs(vector<vector<int>>& adjList, int startVertex) {
    vector<bool> visited(adjList.size(), false);
    dfsUtil(adjList, visited, startVertex);
}

// Example usage:
int main() {
    int numVertices = 6;
    vector<vector<int>> adjList(numVertices);

    adjList[0] = {1, 2};
    adjList[1] = {0, 2, 3};
    adjList[2] = {0, 1, 3, 4};
    adjList[3] = {1, 2, 4, 5};
    adjList[4] = {2, 3, 5};
    adjList[5] = {3, 4};

    int startVertex = 0;
    cout << "DFS traversal starting from vertex " << startVertex << ":\n";
    dfs(adjList, startVertex);
    cout << endl;

    return 0;
}
