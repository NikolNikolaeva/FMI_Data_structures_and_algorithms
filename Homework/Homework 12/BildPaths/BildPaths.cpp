#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Town {
	long  c1;
	long  c2;
	int index;
	long  from;
	long  to;
};

bool edgeComparator(const Town& t1, const Town& t2) {
	if (t1.c1 != t2.c1)
		return t1.c1 < t2.c1;
	return t1.c2 > t2.c2;
}

int findRoot(long node, vector<int>& parents) {
	if (parents[node] == node) {
		return node;
	}

	parents[node] = findRoot(parents[node], parents);
	return parents[node];
}

void kruskal(vector<Town>& edges, vector<Town>& mstEdges, vector<int>& parents)
{
	for (auto const& edge : edges)
	{
		int fromRoot = findRoot(edge.from, parents);
		int toRoot = findRoot(edge.to, parents);
		if (fromRoot != toRoot)
		{
			mstEdges.push_back(edge);
			parents[fromRoot] = toRoot;
		}
	}
}

int main()
{
	int nodes, edgesCount;
	cin >> nodes >> edgesCount;

	vector<Town> edges;
	for (int i = 0; i < edgesCount; ++i)
	{
		long from, to, c1, c2;
		cin >> from >> to >> c1 >> c2;

		edges.push_back({ c1,c2,i + 1, from, to });
	}

	sort(edges.begin(), edges.end(), edgeComparator);
	vector<int> parents(nodes + 1);
	for (int i = 0; i < nodes; ++i)
	{
		parents[i] = i;
	}
	vector<Town> towns;
	kruskal(edges, towns, parents);

	for (int i = 0; i < nodes - 1; i++)
	{
		cout << towns[i].index << '\n';
	}

	return 0;
}