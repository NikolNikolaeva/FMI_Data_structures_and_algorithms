#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;
	std::vector<int> nums(n);

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
		if (nums[i] > max)
			max = nums[i];
	}

	int counter = 0;

	for (int i = 0; i <= max; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((nums[j] | i) == nums[j])
			{
				counter++;
				break;
			}
		}
	}

	std::cout << counter;

	return 0;
}
