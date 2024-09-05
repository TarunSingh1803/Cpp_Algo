#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS iteratively
void dfsIterative(int start, vector<bool>& visited, const vector<vector<int>>& adj) {
    stack<int> s;
    s.push(start);
    
    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            visited[v] = true;
            cout << v << " "; // Process the current node (in this case, print it)

            // Push all adjacent vertices onto the stack
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int numVertices = 5; // Example: Number of vertices in the graph
    vector<vector<int>> adj(numVertices);

    // Example graph: adjacency list
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    vector<bool> visited(numVertices, false);

    cout << "DFS traversal starting from vertex 0:" << endl;
    dfsIterative(0, visited, adj);

    return 0;
}
