#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, n, m;
int arr1[1000001], arr2[1000001];

void binary_search(int start, int end, int target)
{

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr1[mid] == target)
        {
            cout << 1 << '\n';
            return;
        }
        else if (arr1[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << 0 << '\n';
    return;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        sort(arr1, arr1 + n);

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        for (int i = 0; i < m; i++)
        {
            binary_search(0, n - 1, arr2[i]);
        }
    }

    return 0;
}
