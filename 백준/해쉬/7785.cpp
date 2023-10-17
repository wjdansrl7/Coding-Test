#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> p;

    string s1, s2;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;

        if (s2 == "enter")
            p[s1]++;
        else
            p.erase(s1);
    }

    for (auto it = p.rbegin(); it != p.rend(); it++)
    {
        cout << it->first << '\n';
    }

    return 0;
}
