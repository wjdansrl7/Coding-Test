#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // sliding window를 사용해봐?
    int n, x;
    cin >> n >> x;

    vector<int> v;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    int sum = 0;
    for (int i = 0; i < x - 1; i++)
    {
        sum += v[i];
    }

    int l = 0;
    int maxVisited = INT_MIN, maxCnt = 0;
    int tmp = sum;
    for (int r = x - 1; r < n; r++)
    {
        tmp += v[r];
        if (maxVisited < tmp)
        {
            maxVisited = tmp;
            maxCnt = 1;
        }
        else if (maxVisited == tmp)
        {
            maxCnt++;
        }
        tmp -= v[l++];
    }

    if (maxVisited == 0)
    {
        cout << "SAD" << '\n';
    }
    else
    {
        cout << maxVisited << '\n';
        cout << maxCnt << '\n';
    }

    return 0;
}
