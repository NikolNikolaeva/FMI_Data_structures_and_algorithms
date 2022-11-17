#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <stack>
#include "SinglyLinkedList.h"

using namespace std;

int main()
{
    size_t N, Q; std::cin >> N;

    int el(0), pos(0);

    for (size_t i = 0; i < N; i++)
    {
        SinglyLinkedList list;
        std::cin >> Q; std::cin.ignore();
        for (size_t i = 0; i < Q; i++)
        {

            std::string line; getline(std::cin, line);
            std::istringstream istr(line);

            std::string command; istr >> command;

            if (command == "add")
            {
                istr >> el >> pos;
                list.add(el, pos);
            }
            else if (command == "print")
            {
                std::cout << list;
            }
            else if (command == "remove")
            {
                istr >> pos;
                list.remove(pos);
            }
            else if (command == "replace")
            {
                istr >> el;
                list.replace(el);
                std::cout << list << "\n";
            }
            else
            {
                int count(0);
                while (istr)
                {
                    istr >> command;
                    count++;
                }
                i += count - 1;
            }
        }
    }
    return 0;
}