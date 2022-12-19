#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

void dfs(std::map<char, std::unordered_set<char>>& alphabetGraph,
    std::vector<bool>& visitedLetter, std::vector<char>& alphabet, char node)
{
    visitedLetter[node - 'a'] = true;

    for (auto child : alphabetGraph[node])
    {
        if (!visitedLetter[child - 'a'])
        {
            dfs(alphabetGraph, visitedLetter, alphabet, child);
        }
    }

    alphabet.push_back(node);
}

void topologicalSort(std::map<char, std::unordered_set<char>>& alphabetGraph,
    std::vector<char>& alphabet, std::vector<bool>& visitedLetter)
{
    for (auto letters : alphabetGraph)
    {
        if (letters.first == '\0')
            continue;
        if (!visitedLetter[letters.first - 'a']) {
            dfs(alphabetGraph, visitedLetter, alphabet, letters.first);
        }
    }
}

std::map<char, std::unordered_set<char>> alphabetGraph;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    int N;
    std::cin >> N;

    std::string curr;
    std::cin >> curr;

    for (int i = 1; i < N; i++)
    {
        std::string word;
        std::cin >> word;

        int index = 0;
        while (word[index] == curr[index])
        {
            index++;
        }
        alphabetGraph[curr[index]].insert(word[index]);
        curr = word;
    }

    std::vector<bool> visitedLetter(26);
    std::vector<char> alphabet;
    topologicalSort(alphabetGraph, alphabet, visitedLetter);

    for (int i = alphabet.size() - 1; i >= 0; i--)
    {
        std::cout << alphabet[i] << " ";
    }

    return 0;
}
