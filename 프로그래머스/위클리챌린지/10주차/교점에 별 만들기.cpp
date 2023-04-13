#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    set<pair<long, long>> v;

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            long long ad_bc = (long long)line[i][0] * (long long)line[j][1] - (long long)line[i][1] * (long long)line[j][0];
            long long bf_ed = (long long)line[i][1] * (long long)line[j][2] - (long long)line[i][2] * (long long)line[j][1];
            long long ec_af = (long long)line[i][2] * (long long)line[j][0] - (long long)line[i][0] * (long long)line[j][2];

            if (ad_bc != 0)
            {
                if (bf_ed % ad_bc == 0 && ec_af % ad_bc == 0)
                {
                    long long x, y;
                    x = bf_ed / ad_bc;
                    y = ec_af / ad_bc;

                    // v.push_back({x, y});
                    v.insert({x, y});
                }
                else
                    continue;
            }
        }
    }

    // 사각형 표현하기

    long long min_x = 1e12;
    long long max_x = -1e12;
    long long min_y = 1e12;
    long long max_y = -1e12;

    for (const auto &p : v)
    {
        min_x = min(min_x, (long long)p.first);
        max_x = max(max_x, (long long)p.first);
        min_y = min(min_y, (long long)p.second);
        max_y = max(max_y, (long long)p.second);
    }

    for (long long i = min_y; i <= max_y; i++)
    {
        string s = "";
        for (long long j = min_x; j <= max_x; j++)
        {
            s += ".";
        }
        answer.push_back(s);
    }

    for (const auto &p : v)
    {
        answer[abs(p.second - max_y)][abs(p.first - min_x)] = '*';
    }

    return answer;
}