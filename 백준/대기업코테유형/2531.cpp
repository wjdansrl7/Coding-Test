#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    int fish[70000];
    bool fishType[3001];

    for (int i = 0; i < n; i++)
    {
        cin >> fish[i];
    }

    int u = 0;
    for (int i = n; i < 2 * n; i++)
    {
        fish[i] = fish[u++];
    }

    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int maxFish = k;
        for (int j = i; j < i + k; j++)
        {
            if (!fishType[fish[j]])
            {
                fishType[fish[j]] = true;
            }
            else
                maxFish--;
        }

        if (!fishType[c])
        {
            maxFish += 1;
        }

        if (maxSum < maxFish)
        {
            maxSum = maxFish;
        }

        if (maxSum == k + 1)
        {
            break;
        }

        memset(fishType, 0, sizeof(fishType));
    }

    cout << maxSum << '\n';

    return 0;
}
