#include <iostream>

using namespace std;

int cnt;
int result;
int arr[1000000];
long long n, k;
void merge_sort(int arr[1000000], long long p, long long r);
void merge(int arr[1000000], long long p, long long q, long long r);

void merge_sort(int arr[1000000], long long p, long long r)
{

    if (p < r)
    {
        long long q = (p + r) / 2;

        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int arr[1000000], long long p, long long q, long long r)
{
    long long i = p;
    long long j = q + 1;
    long long t = 1;
    static int temp[1000000] = {
        0,
    };

    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[t++] = arr[i++];
            cnt++;
        }
        else
        {
            temp[t++] = arr[j++];
            cnt++;
        }

        if (cnt == k)
        {
            result = temp[t - 1];
        }
    }

    while (i <= q)
    {
        temp[t++] = arr[i++];
        cnt++;
    }
    while (j <= r)
    {
        temp[t++] = arr[j++];
        cnt++;
    }

    if (cnt == k)
    {
        result = temp[t - 1];
    }

    i = p, t = 1;
    while (i <= r)
    {
        arr[i++] = temp[t++];
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    cnt = 0;
    result = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    if (cnt >= k)
    {
        cout << result << '\n';
    }
    else
        cout << -1 << '\n';

    return 0;
}
