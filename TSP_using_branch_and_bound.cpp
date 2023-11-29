#include <bits/stdc++.h>
using namespace std;

int n = 4;

int tspBranchAndBound(int source, vector<vector<int>> &graph, vector<bool> &visited, int cost, int count) {
    // base case
    if (count == n && graph[source][0] != INT_MAX) {
        return min(cost + graph[source][0], INT_MAX);
    }

    int result = INT_MAX;

    for (int i = 0; i < n; i++) {

        if (!visited[i] && graph[source][i] != INT_MAX) {
            visited[i] = true;
            int newCost = cost + graph[source][i];

            result = min(result, tspBranchAndBound(i, graph, visited, newCost, count + 1));

            visited[i] = false;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    vector<bool> visited(n, false);

    visited[0] = true;
    int result = tspBranchAndBound(0, graph, visited, 0, 1);

    cout << "Minimum Cost (Branch and Bound): " << result << endl;

    return 0;
}