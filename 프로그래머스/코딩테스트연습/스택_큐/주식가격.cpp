#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int nCount;

    for (int i = 0; i < prices.size(); i++)
    {
        nCount = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            nCount++;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(nCount);
    }
    return answer;
}

// TODO: 스택을 이용한 풀이

// #include <string>
// #include <vector>
// #include <stack>

// using namespace std;

// vector<int> solution(vector<int> prices) {
//     int size = prices.size();
//     vector<int> answer(size);
//     stack<int> st;

//     for(int i = 0; i < size; i++)
//     {
//         // 스택이 비어있지 않고 스택 마지막 갑싱 현재 값보다 크다면
//         // -> 가격이 떨어졌다면
//         while(!st.empty() && prices[st.top()] > prices[i])
//         {
//             // 가격이 떨어졌으므로 i - 스택 마지막값 대ㅣㅇㅂ
//             answer[st.top()] = i - st.top();
//             // 값제거
//             st.pop();
//             //반복문인 이유: 가격이 같은 값이 유지되었을 경우
//             //현재값보다 계속 작으므로 1개 차이씩 넣어주기 위해서다.
//         }
//         //현재 인덱스를 스택에 넣기
//         st.push(i);
//     }

//     //스택이 빌때까지 반복
//     while(!st.empty())
//     {
//         //위에서 특정위치에 이미 값을 넣었으므로 push_back이나 insert로 하면 안된다.
//         //뒤에서부터 넣어야하므로 size-1 에서 top값을 빼준다.
//         answer[st.top()] = size - st.top() - 1;
//         st.pop();
//     }

//     return answer;
// }