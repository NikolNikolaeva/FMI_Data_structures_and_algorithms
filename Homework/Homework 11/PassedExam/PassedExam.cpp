
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <climits>

std::unordered_map<long long, std::vector<std::pair<long long, long long>>> graph;

long long dijkstra(std::unordered_map<long long, std::vector<std::pair<long long, long long>>> graph,
    std::vector<std::vector<unsigned long int>>& distances, long long start) {
    distances[start][start] = 0;

    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>,
        std::greater<std::pair<long long, long long>>> pq;

    pq.push({ 0, start });

    while (!pq.empty()) {
        long long current = pq.top().second;
        long long distanceToCurrent = pq.top().first;
        pq.pop();

        if (distanceToCurrent > distances[start][current]) continue;

        for (auto edge : graph[current])
        {
            unsigned long int newDistance = distanceToCurrent + edge.first;

            if (newDistance < distances[start][edge.second])
            {
                distances[start][edge.second] = newDistance;
                pq.push({ newDistance, edge.second });
            }
        }
    }
    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long V, E, Q;
    std::cin >> V >> E >> Q;


    for (long long i = 0; i < E; i++)
    {
        long long node1, node2, dist;
        std::cin >> node1 >> node2 >> dist;
        graph[node1].push_back({ dist, node2 });
    }

    std::vector<std::vector<unsigned long int>> distances(V);

    for (long long i = 0; i < V; i++)
    {
        distances[i] = std::vector<unsigned long int>(V, LLONG_MAX);
        dijkstra(graph, distances, i);
    }

    for (long long i = 0; i < Q; i++)
    {
        long long start, end;
        std::cin >> start >> end;

        if (distances[start][end] == LLONG_MAX)
            std::cout << -1 << '\n';
        else
            std::cout << distances[start][end] << '\n';
    }

    return 0;
}
