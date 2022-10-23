
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
	std::string name;
	int grades;
};

int partition(std::vector<Student>& students, int low, int high) {
	Student pivot = students[high];
	int i = low;

	for (int j = low; j < high; j++) {
		if (students[j].grades < pivot.grades)
		{
			std::swap(students[i], students[j]);
			i++;
		}
		else if (students[j].grades == pivot.grades && students[j].name > pivot.name)
		{
			std::swap(students[i], students[j]);
			i++;
		}
	}

	std::swap(students[i], students[high]);
	return i;
}

void quickSort(std::vector<Student>& students, int low, int high) {
	if (low < high)
	{
		int partitionIndex = partition(students, low, high);

		quickSort(students, low, partitionIndex - 1);
		quickSort(students, partitionIndex + 1, high);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<Student> students(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> students[i].name;
	}
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> students[i].grades;
	}

	int studentsSize = students.size();
	quickSort(students, 0, studentsSize - 1);

	for (int i = studentsSize - 1; i >= 0; i--)
	{
		printf("%s ", students[i].name.c_str());
		printf("%d\n", students[i].grades);
	}
	return 0;
}