#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string seven_war = "임진왜란";
    string korea_war = "한국전쟁";

    if (seven_war.compare(korea_war) == 0)
    {
        cout << "같은 문자열" << '\n';
    }
    else
    {
        // 다른 문자열일 경우 -1을 리턴
        cout << "다른 문자열" << '\n';
    }

    return 0;
}
