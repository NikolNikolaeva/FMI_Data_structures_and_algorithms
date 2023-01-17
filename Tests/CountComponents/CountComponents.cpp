//https://www.hackerrank.com/contests/sda-test6-2022-2023-iythgbeu3/challenges/challenge-2351

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, int& components, int start, vector<bool>& visited)
{
    visited[start] = true;
    for (auto child : graph[start])
    {
        if (!visited[child])
            dfs(graph, components, child, visited);

    }
}

int main() {

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        unordered_map<int, vector<int>> graph;
        int components = 0;

        int N, M;
        cin >> N >> M;

        for (int j = 0; j < M; j++)
        {
            int node1, node2;
            cin >> node1 >> node2;

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);

        }

        vector<bool>visited(N, false);

        for (int j = 0; j < N; j++) {
            if (!visited[j]) {
                dfs(graph, components, j, visited);

                components++;
            }
        }

        cout << components << " ";

    }
    return 0;
}
