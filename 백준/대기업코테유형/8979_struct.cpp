// 구현체를 통한 풀이

#include <iostream>
#include <algorithm>
using namespace std;

struct country
{
    int country_number;
    int gold;
    int silver;
    int bronze;
};

bool comp(country a, country b)
{
    if (a.gold > b.gold)
        return true;
    else if (a.gold == b.gold)
    {
        if (a.silver > b.silver)
            return true;
        if (a.silver == b.silver)
        {
            if (a.bronze > b.bronze)
                return true;
        }
    }

    return false;
}

country arr[100];
int n, k;
int n1, n2, n3, n4;
int result = 0, val = 0;

int main(int argc, char const *argv[])
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> n1 >> n2 >> n3 >> n4;
        arr[i].country_number = n1;
        arr[i].gold = n2;
        arr[i].silver = n3;
        arr[i].bronze = n4;
    }

    sort(arr, arr + n, comp);

    for (int i = 0; i < n; i++)
    {
        if (arr[i].country_number == k)
        {
            result = i;
            break;
        }
    }

    for (int i = result - 1;; i--)
    {
        if (arr[i].gold != arr[result].gold || arr[i].silver != arr[result].silver || arr[i].bronze != arr[result].bronze)
        {
            break;
        }
        val++;
    }

    cout << result - val + 1 << '\n';

    return 0;
}
