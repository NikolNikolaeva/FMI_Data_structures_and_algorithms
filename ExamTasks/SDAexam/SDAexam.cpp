//https://www.hackerrank.com/contests/exam-2022-part1-sda/challenges

#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

void bfs(unordered_map<int, set<int>>& graph, int start, vector<long long>& distances, int N) {

    vector<bool> visited(N);

    queue<int> q;
    q.push(start);
    distances[start - 1] = 0;
    visited[start - 1] = true;
    int dist = 1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int curr = q.front();
            q.pop();

            for (auto x : graph[curr])
            {
                if (!visited[x - 1]) {
                    visited[x - 1] = true;
                    distances[x - 1] = dist;
                    q.push(x);
                }
            }
        }
        dist++;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int N, M;
        cin >> N >> M;

        unordered_map<int, set<int>> graph;
        vector<long long> distances(N, -1);

        for (int j = 0; j < M; j++)
        {
            int child1, child2;
            cin >> child1 >> child2;

            graph[child1].insert(child2);
            graph[child2].insert(child1);
        }

        int Ivancho;
        cin >> Ivancho;

        bfs(graph, Ivancho, distances, N);

        for (int j = 0; j < N; j++)
        {
            if (j + 1 != Ivancho)
            {
                if (distances[j] > 0)
                    cout << distances[j] * 6 << " ";
                else                 cout << distances[j] << " ";


            }
        }
        cout << '\n';
    }
    return 0;
}
