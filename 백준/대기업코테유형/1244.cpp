#include <iostream>
using namespace std;

int N, s[101];

void male(int n)
{
    int i = 1;
    while (1)
    {
        if (n * i > N)
            break;
        if (s[n * i] == 0)
            s[n * i] = 1;
        else
            s[n * i] = 0;
        i++;
    }
}

void female(int n)
{
    s[n] = !s[n];

    for (int i = 1; s[n - i] == s[n + i]; i++)
    {
        if (n - i < 1 || n + i > N)
        {
            break;
        }
        s[n - i] = !s[n - i];
        s[n + i] = !s[n + i];
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int x;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        s[i] = x;
    }

    int num;
    cin >> num;

    int f, selectedNum;
    for (int i = 0; i < num; i++)
    {
        cin >> f >> selectedNum;

        if (f == 1)
            male(selectedNum);
        else
            female(selectedNum);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << s[i] << " ";
        if (i % 20 == 0)
            cout << '\n';
    }

    return 0;
}
