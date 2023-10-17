#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n, m;
// unordered_map<string, int> keyword;
unordered_set<string> keyword;

void check(string target)
{
    int j = 0, i;
    for (i = 0; i < target.size(); i++)
    {
        if (target[i] == ',')
        {
            keyword.erase(target.substr(j, i - j));

            j = i + 1;
        }
    }
    keyword.erase(target.substr(j, i - j));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        // keyword[str]++;
        keyword.insert(str);
    }

    string target;
    for (int i = 0; i < m; i++)
    {
        cin >> target;

        check(target);

        cout << keyword.size() << '\n';
    }

    return 0;
}
