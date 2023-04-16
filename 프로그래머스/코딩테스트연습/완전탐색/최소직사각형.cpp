#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    int max_x = -1, max_y = -1;
    for (int i = 0; i < sizes.size(); i++)
    {
        int x = max(sizes[i][0], sizes[i][1]);
        int y = min(sizes[i][0], sizes[i][1]);

        if (max_x < x)
            max_x = x;
        if (max_y < y)
            max_y = y;
    }
    answer = max_x * max_y;
    return answer;
}