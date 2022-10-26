
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 

int ternarySearch(long num, long start, long end,long& candies)
{
	long middle1 = (2 * start + end) / 3;
	long middle2 = (start + 2 * end) / 3;
	if (((num - 1) > middle1 && (num - 1) <= middle2)
		|| (middle1 == middle2 && (num - 1) == middle1)
		|| (middle2 - middle1 == 1 && (num - 1) == middle2))
	{
		return candies;
	}
	else if (middle1 >= (num - 1))
	{
		candies++;
		return ternarySearch(num, start, middle1, candies);
	}
	else
	{
		candies++;
		return ternarySearch(num, middle2 + 1, end, candies);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long P, N;
	std::cin >> P >> N;

	long friends = 0;
	friends = pow(3, P);

	for (long i = 0; i < N; i++)
	{
		long num;
		std::cin >> num;
		long candies = 1;
		candies = ternarySearch(num, 0, friends - 1, candies);
		printf("%d\n", candies);
	}
	return 0;
}

