#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job
{
    int start_time;
    int duration;

    Job(int start_time, int duration) : start_time(start_time), duration(duration) {}
};

struct Compare
{
    bool operator()(Job &job1, Job &job2)
    {
        return job1.duration > job2.duration;
    }
};

void sjf(vector<vector<int>> &jobs)
{
    priority_queue<Job, vector<Job>, Compare> pq;

    int time = 0;
    double total_wait_time = 0;
    double total_turnaround_time = 0;

    for (int i = 0; i < jobs.size(); i++)
    {
        int start_time = jobs[i][0];
        int duration = jobs[i][1];

        // 현재 시간보다 늦게 요청된 작업은 대기 시간을 계산
        if (start_time > time)
        {
            total_wait_time += start_time - time;
            time = start_time;
        }

        pq.push(Job(start_time, duration));

        // 작업 큐가 비어있지 않은 경우, 실행시간이 가장 짧은 작업을 선택하여 실행
        if (!pq.empty())
        {
            Job current_job = pq.top();
            pq.pop();
            time += current_job.duration;
            total_turnaround_time += time - current_job.start_time;
        }
    }

    int num_jobs = jobs.size();
    double avg_wait_time = total_wait_time / num_jobs;
    double avg_turnaround_time = total_turnaround_time / num_jobs;

    cout << "Average Wait Time: " << avg_wait_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main()
{
    vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
    sjf(jobs);
    return 0;
}
