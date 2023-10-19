#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, string> memo;
    int n, m;
    cin >> n >> m;

    string addr, password;
    for (int i = 0; i < n; i++)
    {
        cin >> addr >> password;
        memo[addr] = password;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> addr;
        cout << memo[addr] << '\n';
    }

    return 0;
}
