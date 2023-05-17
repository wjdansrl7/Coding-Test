#include <iostream>
using namespace std;

int main()
{
    string str1 = "abcabc";

    cout << str1.find("a") << endl;   // 0
    cout << str1.find("b") << endl;   // 1
    cout << str1.find("c") << endl;   // 2
    cout << str1.find("abc") << endl; // 0
    cout << str1.find("z") << endl;   // 4294967295

    cout << str1.rfind("a") << endl;   // 3
    cout << str1.rfind("b") << endl;   // 4
    cout << str1.rfind("c") << endl;   // 5
    cout << str1.rfind("abc") << endl; // 3
    cout << str1.rfind("z") << endl;   // 4294967295

    if (str1.rfind("z") == string::npos)
    {
        cout << "검색 문자열이 없습니다." << endl; // 문자열을 찾지 못했을 경우.
    }

    return 0;
}