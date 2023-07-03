// 이분 탐색을 활용 -> O(NlogN)

#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    deque<int> arr;
    deque<int> res;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (res.empty())
        {
            res.push_back(arr[i]);
            continue;
        }

        if (res.back() < arr[i])
        {
            res.push_back(arr[i]);
        }
        else
        {

            int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[idx] = arr[i];
        }
    }

    cout << n - res.size() << '\n';

    return 0;
}
