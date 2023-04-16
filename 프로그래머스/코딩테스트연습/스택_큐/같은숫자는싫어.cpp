#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            answer.push_back(arr[i]);
            continue;
        }
        if (arr[i] == arr[i - 1])
            continue;
        else
            answer.push_back(arr[i]);
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}