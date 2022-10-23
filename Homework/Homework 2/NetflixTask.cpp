
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string films;
	std::cin >> films;

	std::string sortFilms = films;

	std::sort(sortFilms.begin(), sortFilms.end());

	std::vector<int> indexes;

	for (size_t i = 1; i < sortFilms.length()+1; i++)
	{
		int count = 1;
		while (sortFilms[i] == sortFilms[i - 1])
		{
			i++;
			count++;
		}
		if (count == 1)
		{
			for (size_t j = 0; j < films.length(); j++)
			{
				if (films[j] == sortFilms[i - 1])
				{
					indexes.push_back(j);
					break;
				}
			}
		}
	}

	std::sort(indexes.begin(), indexes.end());

	for (size_t i = 0; i < indexes.size(); i++)
	{
		printf("%d ", indexes[i]);
	}
	
	return 0;
}

