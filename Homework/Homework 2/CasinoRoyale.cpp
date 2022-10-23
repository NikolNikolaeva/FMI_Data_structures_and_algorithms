
#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	unsigned N;
	std::cin >> N;

	std::vector<int> numbers(N);
	std::vector<int> sortNums(N);
	unsigned index = 0;
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> numbers[i];
		if (numbers[i] % 2 == 0)
			sortNums[index++] = numbers[i];
	}

	for (size_t i = 0; i < N; i++)
	{
		if (numbers[i] % 2 != 0)
			sortNums[index++] = numbers[i];
	}

	for (size_t i = 0; i < N; i++)
	{
		std::cout << sortNums[i] << '\n';
	}
	return 0;
}
