#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000001];
long long result;

void parametric_search(int n, long long m)
{
    long long start = 1, end = arr[n - 1];

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - mid > 0)
            {
                sum += arr[i] - mid;
            }
        }

        if (sum >= m)
        {
            start = mid + 1;
            result = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long m;
    result = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    parametric_search(n, m);

    cout << result << '\n';

    return 0;
}
