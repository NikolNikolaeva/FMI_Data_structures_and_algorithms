//https://www.hackerrank.com/contests/sda-test6-2022-2023-iythgbeu3/challenges/challenge-3826

#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
	int value;
	int weight;
};

unordered_map<int, set<int>> graph;
unordered_map<int, vector<Node>> graphWeigth;

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;

		graphWeigth[node1].push_back({ node2,weight });
		graphWeigth[node2].push_back({ node1,weight });

		graph[node1].insert(node2);
		graph[node2].insert(node1);
	}

	int K, start;
	cin >> K >> start;

	int sum = 0;
	for (int i = 1; i < K; i++)
	{
		int node;
		cin >> node;

		if (graph[start].count(node))
		{
			for (auto x : graphWeigth[start]) {
				if (x.value == node)
				{
					sum += x.weight;
					break;
				}
			}
			start = node;
			continue;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	cout << sum;
	return 0;
}
