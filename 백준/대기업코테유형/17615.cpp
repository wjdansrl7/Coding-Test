#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    char arr[500002];
    int bSize = 0, rSize = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] == 'R')
        {
            rSize++;
        }
        else
            bSize++;
    }

    int result = 0;
    int cnt1 = 0, cnt2 = 0;
    int start = 0;
    int end = n - 1;
    // 양쪽이 같은 경우
    if (arr[0] == arr[n - 1])
    {

        for (int i = 0; i < n; i++)
        {
            if (arr[start] == arr[i])
            {
                cnt1++;
            }
            else
                break;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[end] == arr[i])
            {
                cnt2++;
            }
            else
                break;
        }

        // 양쪽다 적색 공일 경우
        if (arr[0] == 'R')
        {
            if (cnt1 < cnt2)
            {
                result = min(bSize, rSize - cnt2);
            }
            else
            {
                result = min(bSize, rSize - cnt1);
            }
        }
        else
        {
            if (cnt1 < cnt2)
            {
                result = min(rSize, bSize - cnt2);
            }
            else
            {
                result = min(rSize, bSize - cnt1);
            }
        }
    }
    // 서로 다른 경우
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[start] == arr[i])
            {
                cnt1++;
            }
            else
                break;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[end] == arr[i])
            {
                cnt2++;
            }
            else
                break;
        }

        if (arr[0] == 'R')
        {
            result = min(rSize - cnt1, bSize - cnt2);
        }
        else
        {
            result = min(rSize - cnt2, bSize - cnt1);
        }
    }

    cout << result << '\n';

    return 0;
}
