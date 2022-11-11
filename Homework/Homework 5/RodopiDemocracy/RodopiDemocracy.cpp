
#include <iostream>
#include <queue>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long N;
	std::cin >> N;

	std::deque<int> peopleThroughBridge;

	for (int i = 0; i < N; i++)
	{
		int value;
		std::cin >> value;

		if (peopleThroughBridge.empty() || value > 0)
		{
			peopleThroughBridge.push_back(value);
			continue;
		}
		if (value < 0)
		{
			bool push = true;
			while (peopleThroughBridge.back() > 0)
			{
				if (peopleThroughBridge.back() < -value)
				{
					peopleThroughBridge.pop_back();
					push = true;
				}
				else if (peopleThroughBridge.back() == -value)
				{
					peopleThroughBridge.pop_back();
					push = false;
					break;
				}
				else
				{
					push = false;
					break;
				}
				if (peopleThroughBridge.empty())
				{
					push = true;
					break;
				}
			}
			if (push)
				peopleThroughBridge.push_back(value);
		}
	}

	if (peopleThroughBridge.empty())
	{
		std::cout << '\n';
	}

	for (long i = 0; i < peopleThroughBridge.size(); i++)
	{
		printf("%d ", peopleThroughBridge[i]);
	}
}
