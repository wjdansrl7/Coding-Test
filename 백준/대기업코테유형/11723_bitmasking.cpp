// 이 코드는 bitmasking을 통한 풀이이다.

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "W", stdout);

    int m;
    cin >> m;

    string cmd;
    int x, bitMask = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> x;
            if ((bitMask & (1 << x)) == 0)
                bitMask += (1 << x);
        }
        else if (cmd == "remove")
        {
            cin >> x;
            if (bitMask & (1 << x))
                bitMask -= (1 << x);
        }
        else if (cmd == "check")
        {
            cin >> x;
            if (bitMask & (1 << x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "toggle")
        {
            cin >> x;

            if (bitMask & (1 << x))
                bitMask -= (1 << x);
            else
                bitMask += (1 << x);
        }
        else if (cmd == "all")
            bitMask = (1 << 21) - 1;
        else if (cmd == "empty")
            bitMask = 0;
    }
    return 0;
}

// 참고 : https://donggoolosori.github.io/2020/09/24/boj-11723/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    string order;
    int val, BIT = 0; // BIT를 반드시 0으로 초기화 해준다.
    while (m--)
    {
        cin >> order;
        if (order == "add")
        {
            cin >> val;
            // or 연산자를 통해 val번째 자리수를 1로 채운다.
            BIT |= (1 << val);
        }
        else if (order == "remove")
        {
            cin >> val;
            // ex) 1000 & ~(1000) = 0000
            BIT &= ~(1 << val);
        }
        else if (order == "check")
        {
            cin >> val;
            if (BIT & (1 << val))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "toggle")
        {
            cin >> val;
            // BIT의 val번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
            // val번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
            BIT ^= (1 << val);
        }
        else if (order == "all")
        {
            // ex) 10000 - 1 = 1111
            BIT = (1 << 21) - 1;
        }
        else if (order == "empty")
        {
            BIT = 0;
        }
    }

    return 0;
}