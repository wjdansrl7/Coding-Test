// 내가 푼 풀이

#include <iostream>

using namespace std;

int nCount[1000];
int s;

void make1(int num, int count)
{
    if (num == 1)
    {
        nCount[s++] = count;
        return;
    }

    if (num % 5 == 0)
    {
        make1(num / 5, count + 1);
    }
    if (num % 3 == 0)
    {
        make1(num / 3, count + 1);
    }
    if (num % 2 == 0)
    {
        make1(num / 2, count + 1);
    }

    make1(num - 1, count + 1);
}

int main(int argc, char const *argv[])
{
    s = 0;

    for (int i = 0; i < 1000; i++)
    {
        nCount[i] = 1e9;
    }

    int a;

    cin >> a;

    make1(a, 0);

    sort(nCount, nCount + 100);

    for (int i = 0; i < 100; i++)
    {
        cout << nCount[i] << " ";
    }

    return 0;
}
