#include <iostream>
#include <algorithm> 
#include <vector>

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

		std::vector<int>::iterator firstElement = lower_bound(teams.begin(), teams.end(), min);
		int startIndex = firstElement - teams.begin();
		std::vector<int>::iterator lastElement = upper_bound(teams.begin(), teams.end(), max);
		int endtIndex = (lastElement - teams.begin()) - 1;

		printf("%d\n", endtIndex - startIndex + 1);
	}

	return 0;

}
