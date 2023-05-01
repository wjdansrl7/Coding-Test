/*
TODO: 첫 번째는 내가 시도한 풀이
나의 풀이는 number의 idx부터 접근해서 이후에 나오는 idx가 더 값이 크다면 해당 값의 idx를
ch에 넣어주고 나중에 number를 answer에 복사한 후 해당 idx를 erase하는 방식으로 진행하려고 하였다.
하지만 그렇게 푸는 과정에서 k값이 남는 경우가 생겼고 그래서 오답이 나왔다.
다른 사람들의 풀이를 보니 시작하기전 answersize를 number size에서 k 값을 제거한 후에
사용하였다.
또한 일반적인 tc는 해결하였으나 O(n^2) + ch에서 들어가는 값들을 push_back하는 과정에서
시간복잡도가 n^2 이상이 되어서 시간초과가 나서 문제를 해결하지 못하였다.
아쉬웠다..

*/
// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;

// string solution(string number, int k) {
//     string answer = "";
//     int nCount;
//     vector<int> ch;

//     for(int i = 0; i < number.size(); i++)
//     {
//         nCount = 0;
//         if(k != 0 && i == number.size() - 1)
//         {
//             ch.push_back(number.size()-1);
//             k--;
//             break;
//         }
//         for(int j = i+1; j < number.size(); j++)
//         {
//             if(number[i] >= number[j])
//             {
//                 nCount++;
//             }
//             else
//             {
//                 if(nCount < k)
//                 {
//                     for(int k = i; k < j; k++)
//                         ch.push_back(k);
//                     i = j-1;
//                     k = k - (nCount + 1);
//                     break;
//                 }
//             }
//         }

//     }

//     for(auto n : number)
//     {
//         answer+=n;
//     }

//     for(int i = ch.size()-1; i >=0; i--)
//     {
//         answer.erase(ch[i], 1);
//     }

//     while(k != 0)
//     {
//         answer.erase(answer.end()-1);
//         k--;
//     }

//     return answer;
// }

#include <string>
#include <vector>

using namespace std;

// 1924
/*
maxint = 9 2
maxidx = 1 2

startidx = 2

*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int answerSize = number.size() - k;
    int startidx = 0;

    for (int i = 0; i < answerSize; i++)
    {
        char maxint = number[startidx];
        int maxidx = startidx;
        for (int j = startidx; j <= k + i; j++)
        {
            if (maxint < number[j])
            {
                maxint = number[j];
                maxidx = j;
            }
        }
        startidx = maxidx + 1;
        answer += maxint;
    }

    return answer;
}