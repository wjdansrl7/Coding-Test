#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<char, int> m[101];

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            m[i][str[j]]++;
        }
    }

    int res = 0;
    for (int i = 1; i < n; i++)
    {
        // 같은 구성
        if (m[0] == m[i])
        {
            res++;
            continue;
        }

        if (m[0].size() == m[i].size())
        {
            int cnt = 0;
            for (auto v : m[0])
            {
                cnt += abs(m[i][v.first] - v.second);
            }
            for (auto v : m[i])
            {
                cnt += abs(m[0][v.first] - v.second);
            }
        }
    }

    return 0;
}
