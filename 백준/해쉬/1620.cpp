#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> dict;
    unordered_map<int, string> dict2;

    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> str;

        dict[str] = i + 1;
        dict2[i + 1] = str;
    }

    string target;

    for (int i = 0; i < m; i++)
    {
        cin >> target;

        if (isdigit(target[0]))
        {
            cout << dict2[stoi(target)] << '\n';
        }
        else
        {
            cout << dict[target] << '\n';
        }
    }

    return 0;
}
