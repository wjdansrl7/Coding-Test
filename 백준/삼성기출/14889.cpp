#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[22][22];
bool check[22];
int ans = INT_MAX;

void DFS(int x, int L)
{
    if (x == n / 2)
    {
        int start, link;
        start = 0;
        link = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check[i] == true && chek[j] == true)
                {
                    start += arr[i][j];
                }
                if (check[i] == false && check[j] == false)
                {
                    link += arr[i][j];
                }
            }
        }

        int temp = abs(start - link);
        if (ans > temp)
        {
            ans = temp;
        }

        return;
    }

    for (int i = L; i < n; i++)
    {
        check[L] = true;
        DFS(x + 1, i + 1);
        check[L] = false;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    DFS(0, 1);

    return 0;
}
