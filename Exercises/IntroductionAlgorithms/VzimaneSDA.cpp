
#include <iostream>
#include <vector>

int main()
{
	int minMark;
	std::cin >> minMark;
	unsigned countStudents;
	std::cin >> countStudents;
	std::vector<int> grades(countStudents);

	int negativeMark;
	for (int i = 0; i < countStudents; i++)
	{
		std::cin >> grades[i];
		if (grades[i] < 0)
			negativeMark = grades[i];
	}

	for (int i = 0; i < countStudents; i++)
	{
		if (grades[i] > minMark)
			negativeMark += grades[i] - minMark;
		if (negativeMark >= minMark)
		{
			printf("%s", "yes");
			return 0;
		}
	}

	printf("%s", "no");

	return 0;
}
