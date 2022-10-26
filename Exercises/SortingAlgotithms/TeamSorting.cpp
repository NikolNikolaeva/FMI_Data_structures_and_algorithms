
#include <iostream>
#include <vector>
#include <algorithm>

struct Team
{
	int people;
	int points;
	long long index;
};

int partition(std::vector<Team>& arr, int low, int high)
{
	Team pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (arr[j].points > pivot.points)
		{
			std::swap(arr[i], arr[j]);
			i++;
		}
		else if (arr[j].points == pivot.points && arr[j].people < pivot.people)
		{
			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[i], arr[high]);
	return i;
}

void quickSort(std::vector<Team>& arr, int low, int high)
{
	if (low < high)
	{
		int prtIndex = partition(arr, low, high);
		quickSort(arr, low, prtIndex - 1);
		quickSort(arr, prtIndex + 1, high);
	}
}

int main()
{
	long long N;
	std::cin >> N;

	std::vector<Team> teams(N);

	for (long long i = 0; i < N; i++)
	{
		std::cin >> teams[i].people;
		int otherTeam;
		std::cin >> otherTeam;
		teams[i].index = i;
		teams[i].points = (teams[i].people * teams[i].people) / otherTeam;
	}

	quickSort(teams, 0, N - 1);

	for (long long i = 0; i < N; i++)
	{
		std::cout << teams[i].index + 1 << " ";
	}
	return 0;
}
