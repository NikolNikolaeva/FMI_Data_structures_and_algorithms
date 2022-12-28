#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(unordered_map<int, unordered_set<int>>& graph, int node, int component, unordered_map<int, int>& vertexInComponent, vector<bool>& visited)
{
    visited[node] = true;
    vertexInComponent[node] = component;

    for (auto x : graph[node])
    {
        if (!visited[x])
        {
            dfs(graph, x, component, vertexInComponent, visited);
        }
    }
}

int main() {


    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int Q;
    std::cin >> Q;
    for (int region = 0; region < Q; region++)
    {
        int N, M;
        std::cin >> N >> M;

        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> vertexInComponent;


        for (int i = 0; i < M; i++)
        {
            int node1, node2;
            std::cin >> node1 >> node2;

            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }

        vector<bool> visited(N, false);
        int component = 1;
        for (auto x : graph)
        {
            if (!visited[x.first])
            {
                dfs(graph, x.first, component, vertexInComponent, visited);
                component++;
            }
        }

        std::cout << component << " ";
    }

    return 0;
}