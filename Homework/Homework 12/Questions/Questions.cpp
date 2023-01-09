#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<int>> graph(1005);
unordered_map<int, int> components;
string result;

void dfs(int component, int startNode, vector<bool>& visited)
{
    visited[startNode] = true;
    components[startNode] = component;

    for (auto child : graph[startNode])
    {
        if (!visited[child])
        {
            dfs(component, child, visited);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int component = 1;
    vector<bool> visited(1005, false);

    for (int i = 0; i <= V; i++)
    {
        if (!visited[i]) {
            dfs(component, i, visited);
            component++;
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        vector<bool> visited2(1001, false);
        int type, node1, node2;
        cin >> type >> node1 >> node2;

        if (type == 1)
        {
            if (components[node1] == components[node2])
                result += "1";
            else
                result += "0";
        }
        else if (type == 2)
        {
            if (components[node1] != components[node2])
            {
                dfs(components[node1], node2, visited2);
                graph[node1].push_back(node2);
                graph[node2].push_back(node1);
            }
        }
    }

    cout << result;
    return 0;
}
