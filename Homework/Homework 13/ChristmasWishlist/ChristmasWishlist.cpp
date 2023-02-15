#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int N;
    cin >> N;

    vector<vector<int>> matrix(N + 1);
    vector<int> nums;

    matrix[0] = vector<int>(10081, 0);
    matrix[0][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        int value;
        cin >> value;
        nums.push_back(value);
        matrix[i] = vector<int>(10081, 0);
        matrix[i][0] = 1;
    }

    unsigned long int result = 0;
    for (size_t i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < 10081; j++)
        {
            matrix[i][j] = matrix[i - 1][j];
            if (nums[i - 1] <= j)
            {
                matrix[i][j] = (matrix[i - 1][j - nums[i - 1]] + matrix[i - 1][j]) % 1000000007;
            }
        }
    }

    for (size_t i = 0; i < 10081; i++)
    {
        result += matrix[N][i];
        result %= 1000000007;
    }

    cout << result % (1000000000 + 7);
    return 0;
}
