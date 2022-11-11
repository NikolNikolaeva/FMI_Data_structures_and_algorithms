
#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, T;
	std::cin >> N >> M >> T;

	bool matrix[1001][1001]{ false };


	std::queue<int> applesRow;
	std::queue<int> applesCol;

	int row, col;
	for (int i = 0; i < 2; i++)
	{
		row = col = -1;
		std::cin >> row >> col;

		if (row != -1)
		{
			applesRow.push(row - 1);
			applesCol.push(col - 1);
		}
	}

	for (int i = 0; i < T; i++)
	{
		int size = applesRow.size();

		for (int i = 0; i < size; i++)
		{
			int row = applesRow.front();
			int col = applesCol.front();
			applesRow.pop();
			applesCol.pop();

			matrix[row][col] = true;

			if (col + 1 < M && matrix[row][col + 1] == false)
			{
				applesRow.push(row);
				applesCol.push(col + 1);
				matrix[row][col + 1] = true;
			}
			if (col - 1 >= 0 && matrix[row][col - 1] == false)
			{
				applesRow.push(row);
				applesCol.push(col - 1);
				matrix[row][col - 1] = true;
			}
			if (row + 1 < N && matrix[row + 1][col] == false)
			{
				applesRow.push(row + 1);
				applesCol.push(col);
				matrix[row + 1][col] = true;
			}
			if (row - 1 >= 0 && matrix[row - 1][col] == false)
			{
				applesRow.push(row - 1);
				applesCol.push(col);
				matrix[row - 1][col] = true;
			}

		}
	}

	int countGoodApples = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (matrix[i][j] == false)
				countGoodApples++;
		}
	}

	std::cout << countGoodApples;
	return 0;
}
