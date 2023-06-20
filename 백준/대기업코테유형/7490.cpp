#include <iostream>
#include <string>
using namespace std;

int n;

void makeZero(string start)
{
    // start 문자열의 마지막이 n보다 큰 경우 return;
    if (stoi(start[start.size() - 1]) > n)
    {
        return;
    }

    makeZero(start + "+")
}

int main(int argc, char const *argv[])
{
    int tc;
    cin >> tc;

    for (int T = 0; T < tc; T++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            makeZero(to_string(i));
        }
    }

    return 0;
}
