
#include <iostream>
#include <queue>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	unsigned long int  N, k;
	std::cin >> N >> k;

	std::deque<int> mins;
	std::vector<int> numbers;


	for (unsigned long int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;
		numbers.push_back(num);
	}

	unsigned long int sum = 0;
	for (unsigned long int i = 0; i < N; i++)
	{
		while ((!mins.empty()) && mins.back() >= numbers[i])
		{
			mins.pop_back();
		}
		mins.push_back(numbers[i]);

		if (i >= k && numbers[i - k] == *mins.begin() && mins.size() > 1)
			mins.pop_front();

		if (i >= k - 1)
			sum += *mins.begin();
	}

	std::cout << sum;
	return 0;
}
