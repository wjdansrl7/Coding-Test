#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[30001];

bool cmp(vector<int> &a, vector<int> &b)
{
    return a.size() > b.size();
}

int main(int argc, char const *argv[])
{
    int n, d, k;
    cin >> n >> d >> k;

    vector<vector<int>> taste(d + 1);
    vector<int> maxStudent(d + 1);

    int cnt, x;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt;

        for (int j = 0; j < cnt; i++)
        {
            cin >> x;
            taste[x].push_back(i);
            maxStudent[x]++;
        }

        if (cnt == 0)
        {
            visited[i] = true;
        }
    }

    


    return 0;
}
