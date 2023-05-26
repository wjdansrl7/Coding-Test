#include <iostream>
#include <string>

using namespace std;

long long cnt;

int recursion(string &s, int l, int r)
{
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

// int isPalindrome(string s)
// {
//     return recursion(s, 0, s.size() - 1);
// }

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        cin >> s;

        cout << recursion(s, 0, s.size() - 1) << " " << cnt << '\n';
    }

    return 0;
}
