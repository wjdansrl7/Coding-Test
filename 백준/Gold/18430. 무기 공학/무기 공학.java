import java.io.*;
import java.util.*;

public class Main {
    static int N, M, res = 0;
    static int[][] arr;
    static int[] dx = {-1,0,1,0}, dy = {0, 1, 0, -1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) arr[i][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                boolean[][] visited = new boolean[N][M];
                solve(i, j, visited, 0);
            }
        }
        System.out.println(res);
    }

    static void solve(int x, int y, boolean[][] visited, int sum) {
        // 만약 부메랑의 시작지점이 범위를 벗어나는 경우
        if (!isChecked(x, y, visited)) {
            if (y == M) {
                solve(x + 1, 0, visited, sum);
                return;
            }
            else if (x == N) {
                if (res < sum) res = sum;
                return;
            }
        } else {
            for (int d = 0; d < 4; d++) {
                int nx1 = x + dx[d % 4];
                int ny1 = y + dy[d % 4];
                int nx2 = x + dx[(d + 1) % 4];
                int ny2 = y + dy[(d + 1) % 4];

                if (isChecked(nx1, ny1, visited) && isChecked(nx2, ny2, visited)) {
                    visited[nx1][ny1] = true;
                    visited[nx2][ny2] = true;
                    visited[x][y] = true;
                    sum += (arr[nx1][ny1] + arr[nx2][ny2] + arr[x][y] * 2);
                    solve(x, y + 1, visited, sum);
                    sum -= (arr[nx1][ny1] + arr[nx2][ny2] + arr[x][y] * 2);
                    visited[nx1][ny1] = false;
                    visited[nx2][ny2] = false;
                    visited[x][y] = false;
                }
            }
        }
        solve(x, y+1, visited, sum);
    }
    static boolean isChecked(int x, int y, boolean[][] visited) {
        return x >= 0 && x < N && y >= 0 && y < M && !visited[x][y];
    }
}