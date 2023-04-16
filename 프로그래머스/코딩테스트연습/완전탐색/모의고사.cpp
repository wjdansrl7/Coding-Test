// #TODO: 작성 코드에서 조금 더 최적화
// 순서 반환에 있어서 코드를 너무 복잡하게 짰음. 수정해보려고 함.
// count의 max와 비교하여 max값과 같다면 해당 인덱스들을 vector에 삽입해주었으면 되었다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> result(3, 0);
    int answerSize = answers.size();

    for (int i = 0; i < answerSize; i++)
    {
        if (answers[i] == v1[i % 5])
            result[0]++;
        if (answers[i] == v2[i % 8])
            result[1]++;
        if (answers[i] == v3[i % 10])
            result[2]++;
    }

    int max_result = *max_element(result.begin(), result.end());
    for (int i = 0; i < 3; i++)
    {
        if (max_result == result[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

// TODO: 기존 코드
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // 1,2,3,4,5
// // 2,1,2,3,2,4,2,5
// // 3,3,1,1,2,2,4,4,5,5

// bool comp(pair<int, int> a, pair<int, int> b)
// {
//     if(a.first < b.first)
//         return true;
//     else if(a.first == b.first)
//     {
//         if(a.second < b.second)
//             return true;
//         else
//             return false;
//     }
//     else
//         return false;

// }

// vector<int> solution(vector<int> answers) {
//     vector<int> answer;
//     vector<int> v1 = {1,2,3,4,5};
//     vector<int> v2 = {2,1,2,3,2,4,2,5};
//     vector<int> v3 = {3,3,1,1,2,2,4,4,5,5};

//     int v1_count = 0, v2_count = 0, v3_count = 0;
//     int nCount[4] = {0};

//     vector<vector<int>> v1_an(2000, v1);
//     vector<vector<int>> v2_an(1250, v2);
//     vector<vector<int>> v3_an(1000, v3);

//     vector<pair<int, int>> result;

//     int answerSize = answers.size();

//     for(int i= 0; i < answerSize; i++)
//     {
//         if(answers[i] == v1[i % 5])
//             nCount[1]++;
//             // v1_count++;
//         if(answers[i] == v2[i % 8])
//             nCount[2]++;
//             // v2_count++;
//         if(answers[i] == v3[i % 10])
//             nCount[3]++;
//             // v3_count++;
//     }

//     for(int i = 1; i <= 3; i++)
//     {
//         result.push_back({nCount[i], i});
//     }

//     sort(result.begin(), result.end(), comp);

//     if(result[2].first > result[1].first)
//         answer.push_back(result[2].second);
//     else if(result[2].first == result[1].first)
//     {
//         if(result[1].first == result[0].first)
//         {
//             for(int i = 0; i < 3; i++)
//             {
//                 answer.push_back(result[i].second);
//             }
//         }
//         else
//         {
//             for(int i = 1; i < 3; i++)
//             {
//                 answer.push_back(result[i].second);
//             }
//         }

//     }

// //     if(result[2].first == result[1].first)
// //     {
// //         if(result[1].first == result[0].first)
// //         {
// //             for(int i = 0; i < 3; i++)
// //             {
// //                 answer.push_back(result[i].second);
// //             }
// //         }

// //         for(int i = 1; i <=2; i++)
// //         {
// //             answer.push_back(result[i].second);

// //         }
// //     }

//     return answer;
// }