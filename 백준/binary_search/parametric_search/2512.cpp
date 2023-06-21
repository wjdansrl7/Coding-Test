#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
long long result;
// 최적화(정해진 범위 내에서의 최댓값 혹은 최솟값)의 문제를 결정 문제로 바꿔서 푸는 것.
void parametric_search(int n, long long m)
{
    long long start = 1, end = arr[n - 1];

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid - arr[i] > 0)
            {
                sum += arr[i];
            }
            else
            {
                sum += mid;
            }
        }

        if (sum > m)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            result = mid;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;       // 지방의 수
    long long m; // 총 예산
    result = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cin >> m;

    parametric_search(n, m);

    cout << result << '\n';

    return 0;
}
