#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char game;
    set<string> player;
    cin >> n >> game;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        player.emplace(str);
    }

    int num;
    if (game == 'Y')
        num = 2;
    else if (game == 'F')
        num = 3;
    else
        num = 4;

    cout << player.size() / (num - 1);

    return 0;
}
