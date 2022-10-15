
#include <iostream>
#include <vector>

int main()
{
	//unsigned N;
	//std::cin >> N;
	//int* arr = new int[N];
	//for (size_t i = 0; i < N; i++)
	//{
	//	std::cin >> arr[i];
	//}
	//
	//int income = 0;
	//bool buy = true;
	//int index = 0;
	//for (size_t i = 0; i < N - 1; i = index)
	//{
	//	if (buy)
	//	{
	//		int min = 0;
	//		for (size_t p = 1; p < N; p++)
	//		{
	//			if (arr[p] < arr[min])
	//				min = p;
	//		}
	//		if (min == N - 1)
	//			break;
	//
	//		i = min;
	//		buy = false;
	//	}
	//
	//	int maxIncome = 0;
	//
	//	if (buy == false)
	//	{
	//		for (size_t j = i + 1; j < N; j++)
	//		{
	//
	//			if (arr[j] - arr[i] > maxIncome)
	//			{
	//				maxIncome = arr[j] - arr[i];
	//				index = j;
	//			}
	//
	//		}
	//
	//		income += maxIncome;
	//		buy = true;
	//	}
	//}
	//std::cout << income;

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
}

