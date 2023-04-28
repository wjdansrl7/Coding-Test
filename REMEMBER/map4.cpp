#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{

    map<string, int> music;
    map<string, map<int, int>> musiclist;
    // for (int i = 0; i < genres.size(); i++)
    // {
    //     music[genres[i]] += plays[i];
    //     musiclist[genres[i]][i] = plays[i];
    // }
    musiclist["abc"][1] = 2;

    return 0;
}
