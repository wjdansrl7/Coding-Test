#include <bits/stdc++.h>
using namespace std;

int arr[] = {10, 20, 30, 40};
vector<int> vec;
int res1 = 0, res2 = 0;

void dfs(vector<vector<int>> users, vector<int> emoticons)
{
    if (vec.size() == emoticons.size())
    {
        int cnt = 0;
        int cost = 0;
        for (int i = 0; i < users.size(); i++)
        {
            int tmpCost = 0;
            for (int j = 0; j < emoticons.size(); j++)
                if (users[i][0] <= vec[j])
                    tmpCost += emoticons[j] * (100 - vec[j]) / 100;
            if (users[i][1] <= tmpCost)
                cnt++;
            else
                cost += tmpCost;
        }
        if (res1 < cnt)
        {
            res1 = cnt;
            res2 = cost;
        }
        else if (res1 == cnt)
            if (res2 < cost)
                res2 = cost;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            vec.push_back(arr[i]);
            dfs(users, emoticons);
            vec.pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;

    dfs(users, emoticons);

    answer.push_back(res1);
    answer.push_back(res2);

    return answer;
}