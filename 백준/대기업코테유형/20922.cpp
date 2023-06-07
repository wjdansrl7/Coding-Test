#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int arr[200001] = {
        0,
    };
    cin >> n >> k;

    int num;
    int maxLen = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;

        arr[num]++;

        if (arr[num] <= k)
        {
            len++;
        }
        else
        {
            if (maxLen < len)
            {
                maxLen = len;
                len = 0;
            }
            memset(arr, 0, sizeof(arr));
        }
    }

    cout << maxLen << '\n';

    return 0;
}
