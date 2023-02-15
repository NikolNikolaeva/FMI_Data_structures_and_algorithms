#include <unordered_map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<long, set<long>> graph;
vector<long long> weights(200001);
vector<bool>visited(200001);

void dfs(long curr, vector<long long>& weights, vector<bool>& visited)
{
	visited[curr - 1] = true;
	for (auto x : graph[curr])
	{
		weights[curr - 1] += x;
		dfs(x, weights, visited);
		weights[curr - 1] += weights[x - 1];
	}
}

int main() {

	int m, t;
	cin >> m >> t;

	for (int i = 0; i < m; i++)
	{
		long node1, node2;
		cin >> node1 >> node2;
		graph[node1].insert(node2);
	}

	for (int i = 0; i < m + 1; i++)
	{
		if (!visited[i]) {
			dfs(i + 1, weights, visited);
		}
	}

	for (int i = 0; i < t; i++) {
		long node;
		cin >> node;
		cout << weights[node - 1] << '\n';
	}

	return 0;
}
