#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    // freopen("in5.txt", "r", stdin);
    string str, target;
    int num;

    cin >> str;
    cin >> num;

    int t = 2;
    target += str[0];
    target += str[1];

    int cnt = 0;
    int i = 0;
    while (cnt < 2)
    {
        target += str[t++];
        cnt = 0;

        for (i = 0; i < str.size(); i++)
        {
            if (str[i] != target[i % target.size()])
            {
                break;
            }
        }

        cnt = i / target.size();
    }

    int sum = 0;
    for (int i = 0; i < target.size(); i++)
    {
        sum += int(target[i]) - '0';
    }

    int res = num / target.size() * sum;

    for (int i = 0; i < num % target.size(); i++)
    {
        res += int(target[i]) - '0';
    }

    cout << res << '\n';

    return 0;
}
