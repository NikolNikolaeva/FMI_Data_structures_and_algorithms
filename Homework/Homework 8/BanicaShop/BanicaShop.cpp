
#include <iostream>
#include <vector>
#include <queue>

struct Order {
    long long start;
    long long time;
    long long index;
};

struct CompOrder {
    bool operator()(const Order& first, const Order& other) const {
        if (first.start != other.start) {
            return first.start > other.start;
        }

        return first.time > other.time;
    }
};

struct Comparator {
    bool operator()(const Order& x, const Order& y) const {
        if (x.time != y.time) {
            return x.time > y.time;
        }

        return x.index > y.index;
    }
};

std::priority_queue<Order, std::vector<Order>, CompOrder> orders;
std::priority_queue<Order, std::vector<Order>, Comparator> currOrders;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N;
    std::cin >> N;

    for (long i = 0; i < N; i++)
    {
        long long start, time;
        std::cin >> start >> time;
        orders.push({ start, time, i });
    }

    std::cout << orders.top().index << " ";
    unsigned long int time = orders.top().start + orders.top().time;
    orders.pop();

    while (!orders.empty())
    {
        if (time < orders.top().start && currOrders.empty())
        {
            time = orders.top().start;
        }
        if (orders.top().start <= time)
        {
            while (orders.size() != 0 && orders.top().start <= time)
            {
                currOrders.push(orders.top());
                orders.pop();
            }
        }

        if (!currOrders.empty())
        {
            std::cout << currOrders.top().index << " ";
            time += currOrders.top().time;
            currOrders.pop();
        }
    }

    while (!currOrders.empty())
    {
        std::cout << currOrders.top().index << " ";
        currOrders.pop();
    }

    return 0;
}
