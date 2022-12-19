
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

struct Node {
	int value = 0;
	std::unordered_set<int> reachable;
};

void bfs(std::unordered_map<int, Node>& graph, int sourceNode, std::vector<int>& Vpath, int N)
{
	std::vector<bool> visited(N, false);
	std::queue<int> queue;
	queue.push(sourceNode);
	visited[sourceNode - 1] = true;

	long path = 1;
	int v = 1;
	while (!queue.empty() && v < N) {
		int sizeCurrQue = queue.size();
		for (int j = 0; j < sizeCurrQue; j++)
		{
			int currentNode = queue.front();
			queue.pop();

			for (int i = 1; i <= N; i++)
			{
				if (!visited[i - 1] && i != currentNode && !graph[currentNode].reachable.count(i))
				{
					visited[i - 1] = true;
					queue.push(i);
					Vpath[i - 1] = path;
					v++;
				}
			}
			if (queue.empty() || v == N)
				return;
		}
		path++;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int Q;
	std::cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int N, M;
		std::cin >> N >> M;

		std::unordered_map<int, Node> graphUnreachablePaths;
		std::vector<int> Vpath(N, -1);

		for (int i = 0; i < M; i++)
		{
			int node1, node2;
			std::cin >> node1 >> node2;

			graphUnreachablePaths[node1].reachable.insert(node2);
			graphUnreachablePaths[node2].reachable.insert(node1);
		}

		int start;
		std::cin >> start;

		bfs(graphUnreachablePaths, start, Vpath, N);

		for (int i = 0; i < Vpath.size(); i++)
		{
			if (i != start - 1)
				std::cout << Vpath[i] << " ";
		}

		std::cout << '\n';
	}
	return 0;
}
