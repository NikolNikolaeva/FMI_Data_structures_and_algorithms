
#include <iostream>
#include <vector>
#include <algorithm>

unsigned long int maxElementInArray(std::vector<unsigned long int> qualities)
{
    unsigned long int maxElement = qualities[0];
    for (unsigned long int i = 1; i < qualities.size(); i++)
    {
        if (maxElement < qualities[i])
            maxElement = qualities[i];
    }
    return maxElement;
}

void binarySearch(std::vector<unsigned long int> qualities, unsigned long int start, unsigned long int end, unsigned long int& result, unsigned long int teams)
{
    if (start > end)
        return;
    unsigned long int middle = start + (end - start) / 2;

    unsigned long int currTeams = 0;
    unsigned long int sumQualities = 0;
    for (unsigned long int i = 0; i < qualities.size(); i++)
    {
        if (qualities[i] > middle)
        {
            binarySearch(qualities, middle + 1, end, result, teams);
        }

        sumQualities += qualities[i];

        if (sumQualities > middle)
        {
            currTeams++;
            sumQualities = qualities[i];
        }
    }
    currTeams++;
    if (currTeams <= teams)
    {
        result = middle;
        binarySearch(qualities, start, middle - 1, result, teams);
    }
    else
        binarySearch(qualities, middle + 1, end, result, teams);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned long int developers;
    unsigned long int teams;
    std::cin >> developers >> teams;

    std::vector<unsigned long int> qualities(developers);
    for (unsigned long int i = 0; i < developers; i++)
    {
        std::cin >> qualities[i];
    }

    unsigned long int sumQualities = 0;
    for (unsigned long int i = 0; i < developers; i++)
    {
        sumQualities += qualities[i];
    }


    if (teams == 1)
    {
        std::cout << sumQualities;
        return 0;
    }

    unsigned long int maxElement = maxElementInArray(qualities);
    unsigned long int start = maxElement;
    unsigned long int end = sumQualities;

    unsigned long int result = 0;
    binarySearch(qualities, start, end, result, teams);
    std::cout << result;

    return 0;

}

