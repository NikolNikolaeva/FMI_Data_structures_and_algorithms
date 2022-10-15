
#include <iostream>
#include <vector>
#include <algorithm>

//void conting_sort(std::string& arr)
//{
//	int n = arr.length();
//	std::string arr_copy = "";
//	for (int i = 0; i < n; ++i) {
//		arr_copy[i] += arr[i];
//	}
//	int* count = new int[256];
//	for (int i = 0; i < n; ++i) {
//		count[arr[i]] = count[arr[i]] + 1;
//	}
//	for (int i = 1; i <= 255; ++i) {
//		count[i] += count[i - 1];
//	}
//	for (int i = n - 1; i >= 0; i--) {
//		arr[count[arr_copy[i]] - 1] = arr_copy[i];
//		count[arr_copy[i]] = count[arr_copy[i]] - 1;
//	}
//}


//void conting_sort(std::vector<int>& arr)
//{
//	int n = arr.size();
//	std::vector<int> arr_copy;
//	for (int i = 0; i < n; ++i) {
//		arr_copy[i] = arr[i];
//	}
//	int* count = new int[256];
//	for (int i = 0; i < n; ++i) {
//		count[arr[i]] = count[arr[i]] + 1;
//	}
//	for (int i = 1; i <= 255; ++i) {
//		count[i] += count[i - 1];
//	}
//	for (int i = n - 1; i >= 0; i--) {
//		arr[count[arr_copy[i]] - 1] = arr_copy[i];
//		count[arr_copy[i]] = count[arr_copy[i]] - 1;
//	}
//}

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
}

