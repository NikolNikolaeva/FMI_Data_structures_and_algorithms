
#include <iostream>
#include <queue>
#include <iomanip>

std::priority_queue<long> maxPq;
std::priority_queue<long, std::vector<long>, std::greater<long>> minPq;

int main()
{
	long N;
	std::cin >> N;

	for (long i = 0; i < N; i++)
	{
		long value;
		std::cin >> value;

		if (maxPq.size() == 0)
		{
			maxPq.push(value);
		}
		else if (maxPq.size() <= minPq.size())
		{
			if (value > minPq.top())
			{
				minPq.push(value);
			}
			else
			{
				maxPq.push(value);
			}

			if (minPq.size() - 1 > maxPq.size())
			{
				long curr = minPq.top();
				minPq.pop();
				maxPq.push(curr);
			}
		}
		else
		{
			if (maxPq.top() > value)
			{
				long curr = maxPq.top();
				maxPq.pop();
				minPq.push(curr);
				maxPq.push(value);
			}
			else
			{
				minPq.push(value);
			}
		}

		if (minPq.size() == 0)
		{
			std::cout << std::fixed << std::setprecision(1) << double(maxPq.top()) << '\n';

		}
		else if (maxPq.size() == minPq.size())
		{
			std::cout << std::fixed << std::setprecision(1) << double(maxPq.top() + minPq.top()) / 2.0 << '\n';
		}
		else
		{
			long middle = maxPq.size() > minPq.size() ? maxPq.top() : minPq.top();
			std::cout << std::fixed << std::setprecision(1) << double(middle) << '\n';
		}
	}

	return 0;
}
