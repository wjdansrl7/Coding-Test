#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int, int> m;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void Map_Setting()
{
    for (int i = 0; i < 1; i++)
        m[1]++;

    for (int i = 0; i < 5; i++)
        m[2]++;

    for (int i = 0; i < 3; i++)
        m[3]++;
}

int main(int argc, char const *argv[])
{
    Map_Setting();
    for (auto num : m)
    {
        cout << "Key: " << num.first << " | value: " << num.second << '\n';
    }

    cout << "=========SORT==========\n\n";

    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    for (auto num : vec)
    {
        cout << "Key: " << num.first << " | value: " << num.second << '\n';
    }

    return 0;
}
