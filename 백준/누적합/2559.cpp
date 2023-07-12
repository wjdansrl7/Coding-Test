#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int psum[100001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= k; i++)
    {
        psum[1] += arr[i];
    }

    for (int i = 2; i <= n - k + 1; i++)
    {
        psum[i] = psum[i - 1] - arr[i - 1] + arr[i + k - 1];
    }

    long long res = psum[1];
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (res < psum[i])
        {
            res = psum[i];
        }
    }
    cout << res << '\n';

    return 0;
}
