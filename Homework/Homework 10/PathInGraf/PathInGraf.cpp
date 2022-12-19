#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, std::unordered_set<int>> graph;
std::unordered_map<int, int> elemenntsInComponent;

void dfs(std::unordered_map<int, std::unordered_set<int>>& graph,
    std::vector<bool>& visited, int node, int component,
    std::unordered_map<int, int>& elemenntsInComponent)
{
    visited[node] = true;
    elemenntsInComponent[node] = component;

    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, visited, child, component, elemenntsInComponent);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    for (size_t i = 0; i < M; i++)
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }

    int component = 0;
    std::vector<bool> visitedNodes(1000001);

    for (auto el : graph)
    {
        if (!visitedNodes[el.first])
        {
            dfs(graph, visitedNodes, el.first, component, elemenntsInComponent);
            component++;
        }
    }

    int K;
    std::cin >> K;

    for (size_t i = 0; i < K; i++)
    {
        int node1, node2;
        std::cin >> node1 >> node2;
        if (elemenntsInComponent[node1] == elemenntsInComponent[node2])
            std::cout << 1 << " ";
        else
            std::cout << 0 << " ";
    }

    return 0;
}
