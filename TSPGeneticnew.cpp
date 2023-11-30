#include<bits/stdc++.h>

using namespace std;

 int INF = INT_MAX;

// Function to calculate the cost of traversing the current path
int calculateCost( vector<vector<int>> &graph,  vector<int> &path)
{
    int cost = 0;
    for (int i = 0; i < path.size() - 1; ++i)
    {
        if (graph[path[i]][path[i + 1]] == INF)
        {
            return INF; // If there is no edge, return infinity
        }
        cost += graph[path[i]][path[i + 1]];
    }
    return cost;
}

// Function to perform the branch and bound algorithm for TSP
void tspBranchAndBound( vector<vector<int>> &graph, vector<int> &path, vector<bool> &visited, int &minCost, int cost, int pos)
{
    if (pos == graph.size())
    {
        // If all cities are visited, update the minimum cost
        minCost = min(minCost, cost + graph[path[pos - 1]][path[0]]);
        return;
    }

    for (int i = 0; i < graph.size(); ++i)
    {
        if (!visited[i])
        {
            // Mark the city as visited
            visited[i] = true;
            path[pos] = i;

            // Recursive call to explore further possibilities
            if (graph[path[pos - 1]][i] != INF && cost + graph[path[pos - 1]][i] < minCost)
            {
                tspBranchAndBound(graph, path, visited, minCost, cost + graph[path[pos - 1]][i], pos + 1);
            }

            // Backtrack
            visited[i] = false;
        }
    }
}

int main()
{
    // Define the 3x3 matrix as the graph
    vector<vector<int>> graph = {
        {0, 10, 15},
        {10, 0, 20},
        {15, 20, 0}};

    int numCities = graph.size();

    // Initialize variables
    vector<int> path(numCities);
    vector<bool> visited(numCities, false);
    int minCost = INF;

    // Start from the first city
    path[0] = 0;
    visited[0] = true;

    tspBranchAndBound(graph, path, visited, minCost, 0, 1);

        cout << "Total minimum cost: " << minCost << endl;
        cout << "Path: ";
        for (int i = 0; i < numCities; ++i)
        {
            cout << path[i] + 1<< " ";
        }
        cout << path[0] + 1  << endl;
    
    return 0;
}
