#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int  from;
	int to;
	long weight;

	bool operator<(const Node& other)
	{
		return weight < other.weight;
	}
};

vector<Node> nodes;
unordered_map<int, set<int>> graph;
unordered_set<int> nums;
string result;

int main() {

	long long N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		long node1, node2, weight;
		cin >> node1 >> node2 >> weight;

		nodes.push_back({ node1,node2,weight });
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int value;
		cin >> value;
		nums.insert(value);
	}

	for (auto node : nodes)
	{
		if (!nums.count(node.weight))
		{
			graph[node.from].insert(node.to);
		}
	}

	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int count, start;
		cin >> count >> start;
		bool flag = false;
		for (int j = 0; j < count - 1; j++)
		{
			int node;
			cin >> node;

			if (flag)continue;
			if (graph[start].count(node))
			{
				start = node;
				continue;
			}
			else {
				result += "0";
				flag = true;
			}
		}
		if (!flag)
			result += "1";
	}

	cout << result;
	return 0;
}
