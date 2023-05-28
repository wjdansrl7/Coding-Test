#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;

    int gold[1001];
    int silver[1001];
    int bronze[1001];
    cin >> n >> k;

    int a, b, c, d;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        gold[a] = b;
        silver[a] = c;
        bronze[a] = d;
    }

    int rank = n;
    for (int i = 1; i <= n; i++)
    {
        if (i == k)
        {
            continue;
        }

        if (gold[k] > gold[i])
        {
            rank--;
            continue;
        }
        else if (gold[k] == gold[i])
        {
            if (silver[k] > silver[i])
            {
                rank--;
                continue;
            }
            else if (silver[k] == silver[i])
            {
                if (bronze[k] >= bronze[i])
                {
                    rank--;
                    continue;
                }
            }
        }
    }

    cout << rank << '\n';

    return 0;
}
