#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;

    stack<pair<int, int>> stk1, stk2;

    for (int i = 1; i <= n; i++)
        stk1.push({i, deliveries[i - 1]});
    for (int i = 1; i <= n; i++)
        stk2.push({i, pickups[i - 1]});

    while (1)
    {
        if (stk1.empty() && stk2.empty())
            break;

        int curr_idx, maxIdx = INT_MIN;
        int tmpCap = cap;

        while (!stk1.empty())
        {
            curr_idx = stk1.top().first;
            int curr_val = stk1.top().second;

            stk1.pop();

            if (curr_val == 0)
                continue;

            maxIdx = max(maxIdx, curr_idx);

            if (tmpCap > curr_val)
            {
                tmpCap -= curr_val;
            }
            else if (tmpCap == curr_val)
            {
                break;
            }
            else
            {
                stk1.push({curr_idx, curr_val - tmpCap});
                break;
            }
        }

        tmpCap = cap;
        while (!stk2.empty())
        {
            curr_idx = stk2.top().first;
            int curr_val = stk2.top().second;

            stk2.pop();

            if (curr_val == 0)
                continue;

            maxIdx = max(maxIdx, curr_idx);

            if (tmpCap > curr_val)
            {
                tmpCap -= curr_val;
            }
            else if (tmpCap == curr_val)
            {
                break;
            }
            else
            {
                stk2.push({curr_idx, curr_val - tmpCap});
                break;
            }
        }
        answer += maxIdx * 2;
    }

    return answer;
}