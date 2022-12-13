#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_map<long long, long long> unmAfter;
    std::unordered_map<long long, long long> unmBefore;

    long long n, M;
    std::cin >> n >> M;
    std::vector<long long> v(n);

    for (long long i = 0; i < n; i++)
    {
        long long value;
        std::cin >> value;

        v[i] = value;
        unmAfter[value] += 1;
    }

    long long counter = 0;

    for (long long i = 0; i < n; i++)
    {
        long curr = v[i];
        unmAfter[v[i]]--;

        if (curr % M == 0 && unmAfter.count(v[i] * M) && unmBefore.count(v[i] / M))
        {
            counter += unmBefore[v[i] / M] * unmAfter[v[i] * M];
        }

        unmBefore[v[i]] += 1;
        if (unmAfter[v[i]] == 0)
            unmAfter.erase(v[i]);
    }

    std::cout << counter;
    return 0;
}