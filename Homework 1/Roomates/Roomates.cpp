

#include <iostream>
#include <vector>
#include <string>

int main()
{
	int countLists;
	std::cin >> countLists;

	for (int i = 0; i < countLists; i++)
	{
		unsigned len;
		std::cin >> len;
		std::string str;
		std::cin >> str;

		int countErased = 0;
		for (size_t i = 0; i < len - 1; i++)
		{
			if (str[i] == 'P')
			{
				if (str[i + 1] == 'I')
					continue;
				else countErased++;
			}
			if (str[i] == 'I')
			{
				if (str[i + 1] == 'P')
					continue;
				else countErased++;
			}
		}

		std::cout << countErased << std::endl;

	}

	return 0;
}

