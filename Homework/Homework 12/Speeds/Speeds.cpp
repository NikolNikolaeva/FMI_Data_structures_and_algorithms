#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int minSpeed = INT_MAX;
int maxSpeed = 0;
int resultMin = INT_MIN;
int resultMax = 0;
int difference = INT_MAX;

struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge& edge) const {
        return this->weight < edge.weight;
    }
};


int findRoot(int node, vector<int>& parents) {
    if (parents[node - 1] == node) {
        return node;
    }
    parents[node - 1] = findRoot(parents[node - 1], parents);
    return parents[node - 1];
}

void kruskal(int nodesCount, vector<Edge>& mstEdges, vector<Edge>& edgesSort, int start) {
    vector<int> parents(nodesCount);
    for (int i = 1; i < parents.size() + 1; ++i) {
        parents[i - 1] = i;
    }

    for (size_t i = start; i < edgesSort.size(); i++)
    {
        int fromRoot = findRoot(edgesSort[i].from, parents);
        int toRoot = findRoot(edgesSort[i].to, parents);

        if (fromRoot != toRoot) {
            mstEdges.push_back(edgesSort[i]);

            parents[fromRoot - 1] = toRoot;
        }

        if (mstEdges.size() == nodesCount - 1)
        {
            if (edgesSort[i].weight - edgesSort[start].weight < difference)
            {
                difference = edgesSort[i].weight - edgesSort[start].weight;
                minSpeed = edgesSort[start].weight;
                maxSpeed = edgesSort[i].weight;
            }

            break;
        }
    }
}

int main() {
    int nodes, edgesCount;
    cin >> nodes >> edgesCount;

    vector<Edge> edgesSort;

    for (int i = 0; i < edgesCount; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        edgesSort.push_back({ from, to, weight });
    }

    sort(edgesSort.begin(), edgesSort.end());

    for (int i = 0; i < edgesSort.size(); i++)
    {
        vector<Edge> mstEdges;

        kruskal(nodes, mstEdges, edgesSort, i);
    }

    cout << minSpeed << " " << maxSpeed;
    return 0;
}
