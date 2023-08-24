#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    string str;
    long long n, res;

    cin >> str >> n;

    int i = 3;
    for (; i < str.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (str[j] == str[j + i])
            {
                cnt++;
            }
        }
        if (cnt == i)
        {
            break;
        }
    }

    int sum = 0;
    for (int j = 0; j < i; j++)
    {
        sum += int(str[j] - '0');
    }
    res = (n / i) * sum;

    for (int j = 0; j < n % i; j++)
    {
        res += int(str[j] - '0');
    }

    cout << res;

    return 0;
}