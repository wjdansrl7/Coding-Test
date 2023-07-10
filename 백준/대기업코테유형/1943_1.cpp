#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    for (int tc = 0; tc < 3; tc++)
    {
        int n, money, cnt;
        deque<pair<int, int>> q;

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> money >> cnt;
            q.push_back({money, cnt});
        }

        for (int i = 0; i < n; i++)
        {
            if ((q[i].second & 1)) // 짝수
            {
                continue;
            }
        }
    }

    return 0;
}
