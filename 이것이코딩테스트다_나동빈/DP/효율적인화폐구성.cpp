#include <iostream>

using namespace std;

int rest1, rest2;
int result;

void solution(int money, int count)
{
    if (money < 0)
    {
        return;
    }

    if (money == 0)
    {
        if (result > count)
        {
            result = count;
        }
    }

    solution(money - rest1, count + 1);
    solution(money - rest2, count + 1);
}

int main(int argc, char const *argv[])
{
    int money;

    cin >> money;
    cin >> rest1 >> rest2;

    result = money;

    solution(money, 0);

    if (result == money)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << result << '\n';
    }

    return 0;
}
