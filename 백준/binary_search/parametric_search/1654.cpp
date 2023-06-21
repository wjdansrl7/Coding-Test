#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10001];
long long result;
void parametric_search(int n, int k)
{
    long long start = 1, end = arr[k - 1];

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += arr[i] / mid;
        }

        if (sum >= n)
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
    int n, k;
    result = 0;
    cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + k);

    parametric_search(n, k);

    cout << result << '\n';

    return 0;
}
