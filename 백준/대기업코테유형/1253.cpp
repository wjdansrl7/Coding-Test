#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cnt;
vector<long long> v;

void good(long long target)
{
    int start = 0, end = v.size() - 1;
    int endflag = 1;

    while (start < end)
    {
        if (v[start] == target && endflag)
        {
            endflag = 0;
            start++;
            continue;
        }
        if (v[end] == target && endflag)
        {
            endflag = 0;
            end--;
            continue;
        }

        if (v[start] + v[end] == target)
        {
            cnt++;
            return;
        }
        else if (v[start] + v[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cnt = 0;
    cin >> n;

    long long x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        good(v[i]);
    }

    cout << cnt << '\n';

    return 0;
}
