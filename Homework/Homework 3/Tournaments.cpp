
#include <iostream>
#include <vector>
#include <algorithm>

void binary_searchMin(std::vector<int>& arr, int x, int start, int end, int& index)
{
	int middle = end + (start - end) / 2;
	if (arr[middle] == x && (middle == 0 || arr[middle - 1] < x))
	{
		index = middle;
	}
	else if (arr[middle] > x && (middle == 0 || arr[middle - 1] < x))
	{
		index = middle;
	}
	else if (arr[middle] >= x)
	{
		return  binary_searchMin(arr, x, start, middle - 1, index);
	}
	else
	{
		return binary_searchMin(arr, x, middle + 1, end, index);
	}
}

void binary_searchMax(std::vector<int>& arr, int x, int start, int end, int& index)
{
	int middle = (start + end) / 2;

	if (arr[middle] == x && (middle == end || arr[middle + 1] > x))
	{
		index = middle;
	}
	else if (arr[middle] < x && (middle == end || arr[middle + 1] > x))
	{
		index = middle;
	}
	else if (arr[middle] <= x)
	{
		return binary_searchMax(arr, x, middle + 1, end, index);
	}
	else
	{
		return  binary_searchMax(arr, x, start, middle - 1, index);
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, Q;
	std::cin >> N >> Q;

	std::vector<int> teams(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> teams[i];
	}

	std::sort(teams.begin(), teams.end());

	for (int i = 0; i < Q; i++)
	{
		int min, max;
		std::cin >> min >> max;
		if (min > max)
		{
			printf("%d\n", 0);
			continue;
		}

		int minIndex = 0;
		binary_searchMin(teams, min, 0, N - 1, minIndex);
		int maxIndex = 0;
		binary_searchMax(teams, max, 0, N - 1, maxIndex);

		printf("%d\n", maxIndex - minIndex + 1);
	}
	return 0;
}
