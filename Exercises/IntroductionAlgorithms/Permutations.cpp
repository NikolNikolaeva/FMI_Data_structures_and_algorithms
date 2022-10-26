
#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::string word1;
	std::cin >> word1;
	std::string word2;
	std::cin >> word2;
	std::vector<int> smallLetters(28, 0);

	for (size_t i = 0; i < N; i++)
	{
		smallLetters[word1[i] - 'a' + 1]++;
	}
	for (size_t i = 0; i < N; i++)
	{
		smallLetters[word2[i] - 'a' + 1]--;

	}
	for (size_t i = 0; i < smallLetters.size(); i++)
	{
		if (smallLetters[i] != 0)
		{
			std::cout << "no";
			return 0;
		}
	}

	std::cout << "yes";
	return 0;
}

