import java.util.*;
import java.io.*;

// 우선 x좌표의 위치를 일치시키고 이후에 y좌표를 일치시키면 된다.

// 로봇들은 x의 위치를
class Solution {
    static class Node {
        int idx, next, x, y;
        
        public Node(int idx, int next, int x, int y) {
            this.idx = idx;
            this.next = next;
            this.x = x;
            this.y = y;
        }
    }
    
    static void checkBound(int[][] points, int n) {
        
        for(int i = 0; i < n; i++) {
            if(points[i][0] > x2) x2 = points[i][0];
            if(points[i][0] < x1) x1 = points[i][0];
            
            if(points[i][1] > y2) y2 = points[i][1];
            if(points[i][1] < y1) y1 = points[i][1];
        }
        
    }
    
    static boolean isValid(int x, int y) {
        if(x < x1 || x > x2 || y < y1 || y > y2) return false;
        
        return true;
    }
    
    static void move(int[][] points, int[][] routes) {
        // 1. 경로에 대해 모든 로봇이 한칸씩 움직인다.
        // 2. 현재 부딫힌 로봇을 확인한다.
        // 3. 목적지 경로에 도착했는지 확인한다.
        // 로봇마다 다음 경로지에 idx는 다를 수 있다.
        
        ArrayDeque<Node> q = new ArrayDeque<>();
        
        while(true) {

            for(int i = 1; i <= x; i++) {
                // 아직 최종 목적지까지 도달하지 않은 경우, queue에 삽입
                if(!visited[i]) {
                    q.offer(nodes[i]);
                }
            }
            
            // 더이상 탐색해야할 로봇이 없는 경우
            if(q.size() == 0) break;
            
            // for(int i = 1; i <= x; i++) {
            //     System.out.print("pre" + i + " " + nodes[i].x + " " + nodes[i].y + " " + nodes[i].next + " || ");
            // }
            // System.out.println();
            while(!q.isEmpty()) {
            
                Node p = q.poll();
            
                // 다음 point가 없는 경우
                if(p.next == m) {
                    // visited[p.idx] = true;
                    continue; // 가야할 모든 경로를 도착한 로봇팔
                }
            
                int idx = p.idx;
            
                int next = routes[idx - 1][p.next]; // 이동해야할 포인트
            
                // 이동할 위치의 포인트
                int nx = points[next - 1][0];
                int ny = points[next - 1][1];
                
                if (nodes[idx].x != nx) {
                    if (nodes[idx].x < nx) {
                        nodes[idx].x++;
                    } else {
                        nodes[idx].x--;
                    }
                } else if (nodes[idx].y != ny) {
                    if (nodes[idx].y < ny) {
                        nodes[idx].y++;
                    } else {
                        nodes[idx].y--;
                    }
                }

                // 도착 여부 판단
                if (nodes[idx].x == nx && nodes[idx].y == ny) {
                    nodes[idx].next++;
                }
            
                
                
            }
            
            // for(int i = 1; i <= x; i++) {
            //     System.out.print("after" + i + " " + nodes[i].x + " " + nodes[i].y + " " + nodes[i].next + " || ");
            // }
            // System.out.println();
            
            
            for(int i = 1; i <= x; i++) {
                if(!visited[i]) arr[nodes[i].x][nodes[i].y]++;
            }
            
            res += touch();
            
            for(int i = 1; i <= x; i++) {
                if(nodes[i].next == m && !visited[i]) {
                    visited[i] = true;
                }
            }
                        
        }   
        
    }
    
    static int touch() {
        int count = 0;
        
        for(int i = 0; i <= x2; i++) {
            for(int j = 0; j <= y2; j++) {
                if(arr[i][j] > 1) {
                    count++;
                    // System.out.println(i + " " + j);
                }
            }
        }
        
        for(int i = 0; i <= x2; i++) {
            for(int j = 0; j <= y2; j++) {
                arr[i][j] = 0;
            }    
        }

                
        return count;
    }
    
    static int x, n, m;
    static int res = 0;
    static int[][] arr;
    static int t = 0;
    static Node[] nodes;
    static int x1 = 101, x2 = -1, y1 = 101, y2 = -1;
    static boolean[] visited;
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        
        x = routes.length; // 로봇의 개수 
        n = points.length; // 포인트의 개수
        m = routes[0].length; // 경로의 개수
        visited = new boolean[x+1];
        
        nodes = new Node[x + 1];
        
        for(int i = 1; i < x + 1; i++) {
            int idx = routes[i - 1][0];
            
            // 현재 로봇의 위치를 저장
            nodes[i] = new Node(i, 0, points[idx-1][0], points[idx-1][1]);
        }
        
        checkBound(points, n);
                
        arr = new int[x2+2][y2+2];
        
        // 0초일 때
//         for(int i = 1; i <= x; i++) {
//             arr[nodes[i].x][nodes[i].y]++;
//         }
        
        // touch(t);
        
        move(points, routes);
        
        
        

        return res;
    }
}