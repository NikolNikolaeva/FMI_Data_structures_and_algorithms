
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include "waterSupplies.h"

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> walls(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> walls[i];
	}

	int maxWater = 0;

	for (size_t i = 0; i < N - 1; i++)
	{
		int water;
		for (size_t j = i + 1; j < N; j++)
		{
			int minWall = walls[i] < walls[j] ? walls[i] : walls[j];
			water = (minWall * (j - i));
			if (water > maxWater)
				maxWater = water;
		}
	}

	printf("%d", maxWater);
	return 0;
}
