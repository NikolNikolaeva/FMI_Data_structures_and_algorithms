

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::cin >> N;

	std::string nums = "";
	std::string cappitalLetters = "";
	std::string smallLetters = "";
	std::string input;
	std::cin >> input;

	for (int i = 0; i < N; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			nums += input[i];
		if (input[i] >= 'a' && input[i] <= 'z')
			smallLetters += input[i];
		if (input[i] >= 'A' && input[i] <= 'Z')
			cappitalLetters += input[i];
	}
	std::sort(nums.begin(), nums.end());
	std::sort(smallLetters.begin(), smallLetters.end());
	std::sort(cappitalLetters.begin(), cappitalLetters.end());
	input = nums + smallLetters + cappitalLetters;
	std::cout << input;
	return 0;
}

