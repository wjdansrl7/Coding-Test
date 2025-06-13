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
        
        // 요청 시각에 대하여 정렬
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
        
//         for(int i = 0; i < N; i++) {
//             q.offer(jobList[i]);
//             wq.offer(jobList[i]);
//         }

//         // 기본적인 순차적 스케줄링 처리
        
//         int clock = 0;
        
//         List<Integer> completedSchedule = new ArrayList<>();
        
//         while(!q.isEmpty() && !wq.isEmpty()) {
            
//             if(wq.peek().rTime > clock) {
//                 // 만약 우선순위에 따른 스케줄링이 현재 작업할 수 없는 상태라면
//                 // 순차적으로 들어온 스케줄링을 먼저 처리한다.
                
//                 Job curr = q.poll();
                
//                 if(completedSchedule.contains(curr.num)) continue; // 이미 처리한 스케줄
                
//                 clock = curr.rTime;
//                 int endWork = clock + curr.dTime; // 작업 종료 시각으로 변경
                
//                 clock = endWork; // 작업 종료 시각으로 시간을 변경한다.

//                 avgTime += endWork - curr.rTime; // 반환 시간 저장
                
//                 completedSchedule.add(curr.num); // 작업이 완료된 스케줄을 추가
                
//             } else {
//                 // 우선순위에 있는 큐를 처리할 수 있게 되었다.
                
//                 Job curr = wq.poll();
                
//                 if(completedSchedule.contains(curr.num)) continue;
                
//                 int endWork = clock + curr.dTime;
                
//                 clock = endWork;
                
//                 avgTime += endWork - curr.rTime;
                
//                 completedSchedule.add(curr.num);
//             }
//         }
                
        return avgTime / N;
        
    }
}