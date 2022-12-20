#include <vector>
#include <iostream>
#include <queue>

struct TimeWorkOut {
	int timeIn;
	int timeOut;
};

struct ComparatorInt {
	bool operator()(const TimeWorkOut& t1, const TimeWorkOut& t2)
	{
		return t1.timeIn > t2.timeIn;
	}
};

std::priority_queue<TimeWorkOut, std::vector<TimeWorkOut>, ComparatorInt> pqIntervals;
std::priority_queue<int, std::vector<int>, std::greater<int>> pqEnds;

int main() {

	int n;
	std::cin >> n;

	int maxEnd = 0;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		std::cin >> start >> end;
		pqIntervals.push({ start,end });
		if (end > maxEnd)
			maxEnd = end;
	}

	int maxPeople = 0;

	for (int i = 0; i < maxEnd; i++)
	{
		while (!pqEnds.empty() && pqEnds.top() <= i)
		{
			pqEnds.pop();
		}

		while (!pqIntervals.empty() && pqIntervals.top().timeIn <= i && pqIntervals.top().timeOut >= i)
		{
			pqEnds.push(pqIntervals.top().timeOut);
			pqIntervals.pop();
		}

		if (maxPeople < pqEnds.size())
		{
			maxPeople = pqEnds.size();
		}
	}

	std::cout << maxPeople;
	return 0;
}