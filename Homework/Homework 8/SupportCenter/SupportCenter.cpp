
#include <iostream>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

int main()
{
	int K, T, B, N;
	std::cin >> K >> T >> B >> N;

	std::queue<int> nums;

	for (int i = 0; i < N; i++)
	{
		int value;
		std::cin >> value;
		nums.push(value);
	}

	for (int i = 0; i < B; i++)
	{
		for (int i = 0; (i < T && nums.size() != 0); i++)
		{
			pq.push(nums.front());
			nums.pop();
		}

		for (int i = 0; i < K; i++)
		{
			std::cout << pq.top() << ' ';
			pq.pop();
		}
	}

	return 0;
}
