#include <iostream>
#include <vector>
#include <algorithm>

long unsigned int converIntoNum(std::vector<long unsigned int> row)
{
	long unsigned int number = 0;
	number += row[0];
	for (long unsigned int i = 1; i < row.size(); i++)
	{
		number *= 10;
		number += row[i];
	}
	return number;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long unsigned int N, M;
	std::cin >> N >> M;

	std::vector<long unsigned int> row(M);
	std::vector<long unsigned int> numbers(N);
	long unsigned int counter = 0;

	for (long unsigned int i = 0; i < N; i++)
	{
		for (long unsigned int j = 0; j < M; j++)
		{
			long unsigned int value;
			std::cin >> value;
			row[j] = value;
		}

		long unsigned int num = converIntoNum(row);
		numbers[i] = num;
	}

	for (long unsigned int i = 0; i < N; i++)
	{
		bool same = false;
		for (long unsigned int j = 0; j < N; j++)
		{
			if (numbers[i] == numbers[j] && i != j)
			{
				same = true;
				break;
			}
		}
		if (same == false)
			counter++;
	}

	std::cout << counter;
	return 0;
}
