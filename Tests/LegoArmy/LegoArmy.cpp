#include <vector>
#include <iostream>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main() {

	int n, min;
	std::cin >> n >> min;

	for (int i = 0; i < n; i++)
	{
		int value;
		std::cin >> value;
		pq.push(value);
	}

	int rounds = 0;
	while (pq.top() < min && pq.size() > 1)
	{
		if (pq.top() < min)
		{
			int newValue = pq.top();
			pq.pop();
			newValue += 2 * pq.top();
			pq.pop();
			pq.push(newValue);
		}

		rounds++;
	}

	if (pq.size() == 1 && pq.top() < min)
	{
		std::cout << -1;
		return 0;
	}
	std::cout << rounds;

	return 0;
}