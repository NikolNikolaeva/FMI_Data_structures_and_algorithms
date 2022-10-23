
#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<bool> arr(N+2,false);
	int smallerNumTicket = 0;
	for (size_t i = 0; i < N; i++)
	{
		int ticket;
		std::cin >> ticket;

		if (ticket > 0 && ticket <= N)
			arr[ticket] = true;
	}

	for (size_t i = 1; i < N + 2; i++)
	{
		if (arr[i] == false)
		{
			std::cout << i;
			break;
		}
	}
	
	return 0;
}
