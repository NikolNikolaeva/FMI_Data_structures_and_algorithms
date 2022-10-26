
#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<bool> numbers(70000, false);

	for (size_t i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;
		numbers[num] = true;
	}

	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == true)
			printf("%d ", i);
	}
	return 0;
}

