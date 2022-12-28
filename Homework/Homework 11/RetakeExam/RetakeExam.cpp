#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>

struct Edge {
	unsigned long int dist;
	int value;

	Edge(int dist, unsigned long int value)
	{
		this->dist = dist;
		this->value = value;
	}
};

struct Compare {
	bool operator()(const Edge& one, const Edge& other)
	{
		return one.dist > other.dist;
	}
};

std::unordered_map<int, std::vector<Edge>> graph;

void Dijkstra(int  V, int  start, int  end)
{
	std::vector<unsigned long int> dist(V, ULLONG_MAX);
	std::vector<unsigned long int> paths(V, 0);

	dist[end] = 0;
	paths[end] = 1;

	std::priority_queue<Edge, std::vector<Edge>, Compare> pq;

	pq.push({ 0,end });

	while (!pq.empty())
	{
		int current = pq.top().value;
		unsigned long int  costToCurrent = pq.top().dist;
		pq.pop();

		if (current == start)
			break;

		if (costToCurrent > dist[current])
			continue;

		for (auto neighbour : graph[current])
		{
			int child = neighbour.value;
			unsigned long int costToChildOfCurrent = neighbour.dist;
			unsigned long int newDistance = costToCurrent + costToChildOfCurrent;

			if (dist[child] > newDistance)
			{
				dist[child] = newDistance;
				pq.push({ newDistance, child });
			}

			if (dist[current] < dist[child])
			{
				paths[child] += paths[current];
				paths[start] %= (1000000000 + 7);
			}
		}
	}

	std::cout << paths[start] % (1000000000 + 7);
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(NULL);

	int V, E, start, end;
	std::cin >> V >> E >> start >> end;

	for (int i = 0; i < E; i++)
	{
		int node1, node2, dist;
		std::cin >> node1 >> node2 >> dist;

		graph[node1].push_back({ dist,node2 });
		graph[node2].push_back({ dist,node1 });
	}

	Dijkstra(V, start, end);
	return 0;
}
