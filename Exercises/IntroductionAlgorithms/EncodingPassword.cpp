
#include <iostream>

int main()
{
	std::string str;
	std::cin >> str;

	std::string newStr = "";

	int counter = 1;
	for (size_t i = 1; i < str.length()+1; i++)
	{
		if (str[i] == str[i - 1])
		{
			counter++;
			continue;
		}
		else if (str[i] != str[i - 1] || i == str.length() - 1)
		{
			newStr += (counter + '0');
			newStr += str[i - 1];
			counter = 1;
		}
	}

	std::cout << newStr;
}

