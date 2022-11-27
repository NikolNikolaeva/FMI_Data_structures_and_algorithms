#include <iostream>
#include <set>
#include <map>

int main()
{
	std::set<int> shots;
	std::map<int, int> possibleBoatsInInterval;

	long cells, ships, shipLenght;
	std::cin >> cells >> ships >> shipLenght;

	int maxBoats = (cells + 1) / (shipLenght + 1);

	shots.insert(0);

	possibleBoatsInInterval[0] = 0;
	possibleBoatsInInterval[cells] = maxBoats;

	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int shoot;
		std::cin >> shoot;

		shots.insert(shoot);
		auto itPrev = shots.find(shoot);
		itPrev--;

		int cellsInInterval = shoot - *itPrev - 1;

		if (shoot == cells)
		{
			maxBoats -= possibleBoatsInInterval[cells];
			possibleBoatsInInterval[shoot] = (cellsInInterval + 1) / (shipLenght + 1);
			maxBoats += possibleBoatsInInterval[shoot];

			if (maxBoats < ships)
			{
				std::cout << i;
				return 0;
			}
			continue;
		}

		if (cellsInInterval < shipLenght)
		{
			possibleBoatsInInterval[shoot] = 0;
		}
		else
		{
			possibleBoatsInInterval[shoot] = (cellsInInterval + 1) / (shipLenght + 1);
			maxBoats += possibleBoatsInInterval[shoot];
		}

		auto itNext = shots.find(shoot);
		itNext++;

		if (itNext == shots.end())
		{
			int cellsInInterval = cells - shoot;
			if (cellsInInterval < shipLenght)
			{
				maxBoats -= possibleBoatsInInterval[cells];
				possibleBoatsInInterval[cells] = 0;
			}
			else
			{
				maxBoats -= possibleBoatsInInterval[cells];
				possibleBoatsInInterval[cells] = (cellsInInterval + 1) / (shipLenght + 1);
				maxBoats += possibleBoatsInInterval[cells];
			}

		}
		else
		{
			int cellsInInterval = *itNext - shoot - 1;

			if (cellsInInterval < shipLenght)
			{
				maxBoats -= possibleBoatsInInterval[*itNext];
				possibleBoatsInInterval[*itNext] = 0;
			}
			else
			{
				maxBoats -= possibleBoatsInInterval[*itNext];
				possibleBoatsInInterval[*itNext] = (cellsInInterval + 1) / (shipLenght + 1);
				maxBoats += possibleBoatsInInterval[*itNext];
			}
		}

		if (maxBoats < ships)
		{
			std::cout << i;
			return 0;
		}
	}

	std::cout << -1;
	return 0;
}