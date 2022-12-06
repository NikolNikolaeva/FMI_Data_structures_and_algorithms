#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Request
{
    int value;
    int timeIn;
};

struct Compare {
    bool operator()(const Request& r1, const Request& r2)
    {
        return r1.value > r2.value;
    }
};

std::priority_queue<Request, std::vector<Request>, Compare> pq;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int size = N;
    int time = 0;
    std::vector<int> timeRequest;

    int value;
    std::cin >> value;
    pq.push({ value, 0 });
    time += value;
    int top = pq.top().value;
    timeRequest.push_back(time - pq.top().timeIn);
    pq.pop();
    size--;
    int index = 1;

    while (size != 0)
    {

        for (int i = 0; i < top; i++)
        {
            size--;
            int val;
            std::cin >> val;
            pq.push({ val,index++ });
            if (size == 0)
                break;
        }

        top = pq.top().value;
        time += top;
        timeRequest.push_back(time - pq.top().timeIn);
        pq.pop();
    }

    while (!pq.empty())
    {
        time += pq.top().value;
        timeRequest.push_back(time - pq.top().timeIn);
        pq.pop();
    }

    std::sort(timeRequest.begin(), timeRequest.end());
    std::cout << timeRequest[0] << " " << timeRequest[size - 1];

    return 0;
}
