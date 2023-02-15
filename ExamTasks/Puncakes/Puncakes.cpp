//https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/copy-from/1355974585

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long const MAX_TIME = 10000000000000;

vector<long> chefs;

long  binarySearch(long start, long end, long Puncakes)
{
	long result = 0;
	long mid;

	while (start <= end) {

		mid = (start + end) / 2;

		long  currP = 0;
		for (auto x : chefs)
		{
			currP += mid / x;
		}

		if (Puncakes > currP)
		{
			start = mid + 1;
		}
		else if (currP >= Puncakes)
		{
			end = mid - 1;
			result = mid;
		}
	}
	return result;
}

int main() {

	long  Puncakes, K;
	cin >> Puncakes >> K;

	for (long i = 0; i < K; i++)
	{
		long  time;
		cin >> time;
		chefs.push_back(time);
	}

	cout << binarySearch(1, MAX_TIME, Puncakes);

	return 0;
}
