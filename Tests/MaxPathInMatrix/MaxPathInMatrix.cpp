#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<vector<int>> matrix(N);
	set<pair<int, int>> diag;

	for (int i = 0; i < N; i++)
	{
		matrix[i] = vector<int>(N, 0);
		for (int j = 0; j < N; j++)
		{
			int value;
			cin >> value;
			matrix[i][j] = value;
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;
		diag.insert({ row,col });
	}

	vector<vector<int>> matrixValues(N);

	for (int i = 0; i < N; i++)
	{
		matrixValues[i] = vector<int>(N, 0);
		for (int j = 0; j < N; j++)
		{
			matrixValues[i][j] = matrix[i][j];

			if (i == 0 && j == 0)
			{
				continue;
			}
			else
			{
				if (i == 0)
				{
					matrixValues[i][j] += matrixValues[i][j - 1];
				}
				else if (j == 0)
				{
					matrixValues[i][j] += matrixValues[i - 1][j];
				}
				else
				{
					if (diag.count({ i,j }))
					{
						int max = matrixValues[i][j - 1] > matrixValues[i - 1][j] ? matrixValues[i][j - 1] : matrixValues[i - 1][j];
						int max2 = max > matrixValues[i - 1][j - 1] ? max : matrixValues[i - 1][j - 1];
						matrixValues[i][j] += max2;
					}
					else
					{
						int max = matrixValues[i][j - 1] > matrixValues[i - 1][j] ? matrixValues[i][j - 1] : matrixValues[i - 1][j];
						matrixValues[i][j] += max;
					}
				}
			}
		}
	}

	cout << matrixValues[N - 1][N - 1];
	return 0;
}
