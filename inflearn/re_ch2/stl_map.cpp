#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    string a = "It is time to Study Go Go";
    // map은 이진 트리 형태, A: 65~90 a: 97~122, 오름차순으로 자동 정렬
    // 사전 순으로 정렬해서 출력하라 -> map을 사용
    // map<char, int> ch; // 이진 트리 형태이기때문에 자료검색: log(n)
    // unordered_map<char, int> ch; 자료 검색 O(1) 일직선상으로 -> 해쉬 자료형으로만 사용하
    // 정렬은 필요없을때 -> 데이터가 많아지면 더 느려짐 -> 해쉬 충돌, 현업

    map<string, int> ch;
    string tmp;

    // for (auto x : a)
    // {
    //     if (x != ' ')
    //         ch[x]++;
    // }

    // for (auto it = ch.begin(); it != ch.end(); it++)
    // {
    //     cout << it->first << " " << it->second << '\n';
    // }
    // ch['K']; key 생성 -> 값은 0으로 초기화

    for (auto x : a)
    {
        if (x == ' ')
        {
            ch[tmp]++;
            tmp.clear();
        }
        else
            tmp += x;
    }
    ch[tmp]++; // 마지막 단어

    for (auto x : ch)
    {
        cout << x.first << " " << x.second << '\n';
    }

    return 0;
}
