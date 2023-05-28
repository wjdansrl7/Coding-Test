#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, pair<int, pair<int, string>>> &a, pair<int, pair<int, pair<int, string>>> &b)
{
    if (a.first == b.first)
    {
        if (a.second.first == b.second.first)
        {
            if (a.second.second.first == b.second.second.first)
            {
                // 이름에 대한 사전 순
                return a.second.second.second < b.second.second.second;
            }

            // 수학 점수에 대한 내림차순
            return a.second.second.first > b.second.second.first;
        }

        // 영어 점수에 대한 오름차순
        return a.second.first < b.second.first;
    }

    // 국어 점수에 대한 내림차순
    return a.first > b.first;
}

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    vector<pair<int, pair<int, pair<int, string>>>> students;

    cin >> n;

    string name;
    int l, e, m;

    for (int i = 0; i < n; i++)
    {
        cin >> name >> l >> e >> m;
        students.push_back({l, {e, {m, name}}});
    }

    sort(students.begin(), students.end(), comp);

    for (auto student : students)
        cout << student.second.second.second << '\n';

    return 0;
}
