#include <iostream>
#include <string>

using namespace std;

int arr[65][65];
int n;

void dfs(int size, int x, int y)
{
    if (size == 1)
    {
        cout << arr[x][y];
        return;
    }

    bool one = true;
    bool zero = true;

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (arr[i][j] == 1)
                zero = false;
            else
                one = false;
        }
    }

    if (one)
        cout << 1;
    else if (zero)
    {
        cout << 0;
    }
    else
    {
        cout << "(";
        dfs(size / 2, x, y);
        dfs(size / 2, x, y + size / 2);
        dfs(size / 2, x + size / 2, y);
        dfs(size / 2, x + size / 2, y + size / 2);
        cout << ")";
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < n; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }

    dfs(n, 0, 0);

    return 0;
}
