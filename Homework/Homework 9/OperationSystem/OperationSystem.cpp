#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

unordered_map<string, set<string>> fils;

void operationsDirectories(string command, string& currDirectory, int& indexCurrDirectory, vector<string>& vDir)
{
	if (command == "mkdir")
	{
		string name;
		cin >> name;

		if (fils[currDirectory].count(name))
		{
			cout << "Directory already exists\n";
		}
		else
		{
			fils[currDirectory].insert(name);
		}
	}
	else if (command == "ls")
	{
		for (auto dir : fils[currDirectory])
		{
			cout << dir << " ";
		}
		std::cout << "\n";
	}
	else if (command == "pwd")
	{
		std::cout << currDirectory << "\n";
	}
	else if (command == "cd")
	{
		string name;
		cin >> name;

		if (name == "..")
		{
			if (indexCurrDirectory == 0)
			{
				cout << "No such directory\n";
			}
			else
			{
				indexCurrDirectory--;
				vDir.pop_back();
				currDirectory = vDir[indexCurrDirectory];
			}
		}
		else if (!fils[currDirectory].count(name))
		{
			cout << "No such directory\n";
		}
		else
		{
			currDirectory += name + "/";
			vDir.push_back(currDirectory);
			indexCurrDirectory++;
			fils[currDirectory];
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	fils["/"];
	string currDirectory = "/";
	vector<string> vDir;
	vDir.push_back(currDirectory);
	int indexCurrDirectory = 0;

	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;

		operationsDirectories(command, currDirectory, indexCurrDirectory, vDir);
	}

	return 0;
}
