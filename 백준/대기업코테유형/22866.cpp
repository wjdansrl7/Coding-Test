#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 이전 값들을 참고한다?????

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<pair<int, int>> building;
    // vector<pair<int, int>> tmp;

    cin >> n;

    int l;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        building.push_back({l, i + 1});
    }

    // tmp = building;

    // sort(tmp.begin(), tmp.end());

    // int maxIdx, minIdx;
    // if (tmp[n - 1].first == tmp[n - 2].first)
    // {
    //     maxIdx = tmp[n - 1].second - 1;
    //     minIdx = tmp[n - 2].second - 1;
    // }
    // else
    // {
    //     if (tmp[n - 1].second < tmp[n - 2].second)
    //     {
    //         maxIdx = tmp[n - 2].second - 1;
    //         minIdx = tmp[n - 1].second - 1;
    //     }
    //     else
    //     {
    //         minIdx = tmp[n - 2].second - 1;
    //         maxIdx = tmp[n - 1].second - 1;
    //     }
    // }

    vector<vector<int>> res(n);

    for (int i = 0; i < n; i++)
    {
        stack<int> stk;

        stk.push(building[i].first);

        // if (i - 1 < minIdx)
        // {
        //     minIdx = 0;
        // }
        for (int j = i - 1; j >= 0; j--) // 왼쪽 방향
        {
            if (stk.top() < building[j].first)
            {
                stk.pop();
                stk.push(building[j].first);
                res[i].push_back(building[j].second);
            }
        }

        while (!stk.empty())
        {
            stk.pop();
        }

        stk.push(building[i].first);
        // // TODO:
        // if (i + 1 > maxIdx)
        // {
        //     maxIdx = n - 1;
        // }

        for (int j = i + 1; j <= n - 1; j++) // 오른쪽 방향
        {
            if (stk.top() < building[j].first)
            {
                stk.pop();
                stk.push(building[j].first);
                res[i].push_back(building[j].second);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (res[i].size() == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << res[i].size() << " " << res[i][0] << '\n';
        }
    }

    return 0;
}
