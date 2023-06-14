#include <iostream>
#include <vector>
// #include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int n;
int ans;
deque<pair<int, int>> q;
vector<int> res;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}
void sky()
{
    // ans++;
    // int height = q.front().second;

    ans++;
    res.push_back(q.front().second);

    while (!q.empty())
    {

        int curr = q.front().second;

        q.pop_front();

        if (curr == 0)
        {
            res.clear();
            continue;
        }

        if (q.front().second > curr)
        {
            ans++;
            res.push_back(q.front().second);
        }
        else
        {
            if (find(res.begin(), res.end(), q.front().second) == res.end() && q.front().second != 0)
            {
                ans++;
                res.push_back(q.front().second);
            }
        }

        // q.pop();

        // if (q.front().second > height)
        // {
        //     ans++;
        //     height = q.front().second;

        // }
        // else if (q.front().second == 0)
        // {
        //     height = 0;
        // }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int x, y;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        q.push_back({x, y});
    }

    sort(q.begin(), q.end(), comp);

    sky();

    cout << ans << '\n';

    return 0;
}
