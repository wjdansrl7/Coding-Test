#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int arr[100001] = {
        0,
    };
    queue<int> q;

    cin >> n >> k;

    int num;
    int maxLen = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;

        arr[num]++;
        q.push(num);

        if (arr[num] <= k) // 넘지 않는 경우
        {
            len++;
        }
        else // 넘는 경우
        {
            if (maxLen < len)
            {
                maxLen = len;
            }
            while (q.front() != num)
            {
                arr[q.front()]--;
                q.pop();
            }

            q.pop(); // q.front() == num
            arr[num]--;
            len = q.size();
        }
    }

    if (maxLen < q.size())
    {
        maxLen = q.size();
    }

    cout << maxLen << '\n';

    return 0;
}
