/*
해당 문제의 접근을 떠올리는게 쉽지 않아 다른 사람들의 코드를 참고하였다.
이 문제의 핵심은 카메라의 위치이다. 처음 차량이 진입하면 카메라가 한 대 필요할 것이다.
이 후 다른 차량이 들어왔을 때, 해당 차량의 진입이 이전 차량의 진출 위치보다 작다면 카메라 한대로
두 차량을 사진 찍을 수 있을 것이고, 만약 다음 차량의 진입 시점이 이전 차량의 진출 시점보다 크다면
카메라를 한대 추가하고 다음 차랑의 진출 시점에 카메라 위치를 저장한다. 또한
다음 들어오는 차량의 진출점이 이전 차량의 진출점보다 작다면 다음 차량의 진출점의 카메라 위치를
수정하여서 카메라를 추가하지 않고 두 차량을 모두 카메라에 찍도록 할 수 있게 된다.

이 문제가 그리디라는 주제를 알지 못했다면 그리디를 가지고 풀어야 하는 것에 어려움을 느겼을 것 같다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 1;

    // 차량의 위치를 정렬
    sort(routes.begin(), routes.end());

    // 처음 들어오는 차량의 진출점에 카메라를 설치한다.
    int temp = routes[0][1];

    for (auto a : routes)
    {
        // 카메라가 설치되어 있는 부분보다 들어오는 차량의 진입 위치가 더 크다면
        // 카메라를 추가 설치해주고, 새롭게 추가된 카메라의 위치는 들어오는 차량의
        // 진출 위치로 설정한다.
        if (temp < a[0])
        {
            answer++;
            temp = a[1];
        }

        // 만약 들어오는 차량의 진출 위치가 기존의 차량의 진출 위치보다 작다면
        // 카메라의 위치를 들어오는 차량의 진출점으로 설정하여서 두 차량을 모두
        // 단속 카메라에 찍히도록 설정한다.
        if (temp >= a[1])
        {
            temp = a[1];
        }
    }

    return answer;
}

// 두 번째 풀이

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;

    sort(routes.begin(), routes.end(), comp);

    int camera = -30001;
    for (int i = 0; i < routes.size(); i++)
    {
        if (routes[i][0] > camera)
        {
            camera = routes[i][1];
            answer++;
        }
    }

    return answer++;
}
