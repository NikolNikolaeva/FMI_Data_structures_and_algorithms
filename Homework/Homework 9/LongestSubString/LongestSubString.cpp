#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::string str2;
	std::cin >> str1 >> str2;

	int longest = 0;

	for (size_t i = 0; i < str1.length(); i++)
	{
		char curr = str1[i];
		for (size_t j = 0; j < str2.length(); j++)
		{
			if (str2[j] == curr)
			{
				int maxSize = 0;
				int index = i;
				while (str1[index] == str2[j])
				{
					maxSize++;
					index++;
					j++;
				}

				if (longest < maxSize)
					longest = maxSize;
			}
		}
	}

	std::cout << longest;
	return 0;
}
