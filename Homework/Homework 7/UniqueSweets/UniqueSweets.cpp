
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned long int Q;

    std::cin >> Q;

    for ( long  i = 0; i < Q; i++)
    {
         long  N;
        std::cin >> N;
         long  count = 0;
        std::set< long > s;
        std::queue<long> q;

        for ( long  j = 0; j < N; j++)
        {
            long sweet;
            std::cin >> sweet;
            if (s.find(sweet)!=s.end())
            {
                while (q.front() != sweet)
                {
                    s.erase(q.front());
                    q.pop();
                }
                s.erase(q.front());
                q.pop();
            }
            s.insert(sweet);
            q.push(sweet);

            if (q.size() > count)
                count = q.size();
        }

        std::cout << count << '\n';
    }
        return 0;
}
