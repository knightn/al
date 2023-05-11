#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& adjList, int startVertex) {
    queue<int> q;
    vector<bool> visited(adjList.size(), false);
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        cout << currVertex << " ";

        for (int neighbor : adjList[currVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
    cout << "BFS traversal starting from vertex " << startVertex << ":\n";
    bfs(adjList, startVertex);
    cout << endl;

    return 0;
}
