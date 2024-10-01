/**
 * packageName    : _241001
 * fileName       : BOJ_G3_14890_경사로
 * author         : moongi
 * date           : 10/1/24
 * description    :
 */

import java.util.*;
import java.io.*;

public class Main {
    static int N, L, res = 0;
    static int[][] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        arr = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            if(canRow(i)) res++;
            if (canCol(i)) res++;
        }

        System.out.println(res);
    }
    
    static boolean canRow(int x) {
        boolean[] visited = new boolean[N];

        for (int i = 0; i < N-1; i++) {
            int diff = arr[x][i] - arr[x][i + 1];

            if (diff > 1 || diff < -1) return false;
            // 오르막길
            else if (diff == -1) {
                for (int j = 0; j < L; j++) {
                    // 1. 낮은 칸의 높이가 서로 다른 경우
                    if (i < j || arr[x][i] != arr[x][i-j]) return false;
                    // 2. 이미 경사로가 설치되어 있는 경우
                    if (visited[i-j]) return false;
                    visited[i - j] = true; // 경사면 설치
                }
            }
            // 내리막길
            else if (diff == 1) {
                for (int j = 1; j <= L; j++) {
                    // 1. 높은 칸의 높이와 높이 차가 1이 아닌 경우
                    if (i + j >= N || arr[x][i]-1 != arr[x][i+j]) return false;
                    // 2. 이미 경사로가 설치된 경우
                    if (visited[i+j]) return false;
                    visited[i+j] = true; // 경사면 설치
                }
            }
        }
        return true;
    }

    static boolean canCol(int x) {
        boolean[] visited = new boolean[N];

        for (int i = 0; i < N-1; i++) {
            int diff = arr[i][x] - arr[i+1][x];

            if (diff > 1 || diff < -1) return false;
                // 오르막길
            else if (diff == -1) {
                for (int j = 0; j < L; j++) {
                    // 1. 낮은 칸의 높이가 서로 다른 경우
                    if (i < j || arr[i][x] != arr[i-j][x]) return false;
                    // 2. 이미 경사로가 설치되어 있는 경우
                    if (visited[i-j]) return false;
                    visited[i - j] = true; // 경사면 설치
                }
            }
            // 내리막길
            else if (diff == 1) {
                for (int j = 1; j <= L; j++) {
                    // 1. 높은 칸의 높이와 높이 차가 1이 아닌 경우
                    if (i+j >= N || arr[i][x]-1 != arr[i+j][x]) return false;
                    // 2. 이미 경사로가 설치된 경우
                    if (visited[i+j]) return false;
                    visited[i+j] = true; // 경사면 설치
                }
            }
        }
        return true;
    }
}