import java.util.*;
import java.io.*;

class Solution {
    
    static class Job implements Comparable<Job> {
        int num, rTime, dTime;
        
        public Job(int num, int rTime, int dTime) {
            this.num = num;
            this.rTime = rTime;
            this.dTime = dTime;
        }
        
        @Override
        public int compareTo(Job o) {
            if(this.dTime == o.dTime) {
                if(this.rTime == o.rTime) {
                    return this.num - o.num;
                }
                return this.rTime - o.rTime;
            }
            return this.dTime - o.dTime;
        }
    }
    
    static Job[] jobList;
    public int solution(int[][] jobs) {
        int avgTime = 0;
        int N = jobs.length;
        jobList = new Job[N];
        
        for(int i = 0; i < N; i++) {
            jobList[i] = new Job(i, jobs[i][0], jobs[i][1]);
        }
        
        Arrays.sort(jobList, (o1, o2) -> o1.rTime - o2.rTime);
        
        ArrayDeque<Job> q = new ArrayDeque<>();
        PriorityQueue<Job> wq = new PriorityQueue<>();
        
        int idx = 0, clock = 0;
        
        while(idx < N || !wq.isEmpty()) {

            while(idx < N && jobList[idx].rTime <= clock) {
                wq.offer(jobList[idx++]);
            }
            if(wq.isEmpty()) {
                clock = jobList[idx].rTime;
            } else {
                Job job = wq.poll();
                clock += job.dTime;
                avgTime += clock - job.rTime;
            }
        }
                        
        return avgTime / N;
        
    }
}