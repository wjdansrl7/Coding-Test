#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int score[100];
bool visited[10001];
vector<int> canScore;
int answer;

int main(int argc, char const *argv[])
{

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        N = 0;
        memset(score, 0, sizeof(score));
        memset(visited, false, sizeof(visited));
        canScore.clear();
        answer = 0;

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> score[i];
        }

        canScore.push_back(0);
        visited[0] = true;

        for (int i = 0; i < N; i++)
        {
            int v_size = canScore.size();

            for (int j = 0; j < v_size; j++)
            {
                int newScore = canScore[j] + score[i];

                if (!visited[newScore])
                {
                    canScore.push_back(newScore);
                    visited[newScore] = true;
                }
            }
        }

        answer = canScore.size();

        cout << "#" << tc + 1 << " " << answer << '\n';
    }

    return 0;
}
