#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long findMinSeconds(long long lists, std::vector<int>& seconds)
{
	long long end = LLONG_MAX;
	long long start = 0;
	long long result = LLONG_MAX;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < seconds.size(); i++)
		{
			sum += mid / seconds[i];
			if (sum >= lists)
				break;
		}
		if (sum >= lists)
		{
			result = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return result;
}

int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long neededLists;
	int printers;
	std::cin >> neededLists >> printers;
	std::vector<int> secondsPerPrinter(printers);
	for (int i = 0; i < printers; i++)
	{
		std::cin >> secondsPerPrinter[i];
	}

	long long result = findMinSeconds(neededLists, secondsPerPrinter);
	std::cout << result;
	return 0;
}

