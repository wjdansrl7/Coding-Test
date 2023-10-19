#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, string> &a, const pair<string, string> &b)
{
    return a.first < b.first;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string group, member;
    int num;
    unordered_map<string, string> gg;

    for (int i = 0; i < n; i++)
    {
        cin >> group >> num;

        for (int j = 0; j < num; j++)
        {
            cin >> member;
            gg[member] = group;
        }
    }

    string str;
    int s;

    vector<pair<string, string>> vgg(gg.begin(), gg.end());
    sort(vgg.begin(), vgg.end(), cmp);

    for (int i = 0; i < m; i++)
    {
        cin >> str >> s;

        if (s == 1)
        {
            for (auto v : gg)
            {
                if (v.first == str)
                {
                    cout << v.second << '\n';
                    break;
                }
            }
        }
        else
        {
            for (auto v : vgg)
            {
                if (v.second == str)
                {
                    cout << v.first << '\n';
                }
            }
        }
    }

    return 0;
}
