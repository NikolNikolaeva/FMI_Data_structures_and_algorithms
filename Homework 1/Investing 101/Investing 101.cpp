
#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> arr(N);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	int income = 0;
	int minElementIndex = 0;
	bool buy = true;

	for (size_t i = 0; i < N; i++)
	{

		if (buy == false)
		{
			if (i == N - 1)
			{
				if (arr[i] - arr[minElementIndex] > 0)
					income += arr[i] - arr[minElementIndex];
				break;
			}
			if ((arr[i + 1] < arr[i]) && arr[minElementIndex] < arr[i])
			{
				income += arr[i] - arr[minElementIndex];
				buy = true;
			}
			continue;
		}

		if (buy == true)
		{
			if (i == N - 1)
				break;
			if (arr[i + 1] > arr[i])
			{
				minElementIndex = i;
				buy = false;
			}
			continue;
		}

	}

	std::cout << income;
	return 0;
}

