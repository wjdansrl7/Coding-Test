import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] arr, dp;
    static int[] dx = {-1,0,1,0}, dy = {0, 1, 0, -1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());

        arr = new int[n][n];
        dp = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                DFS(i, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, dp[i][j]);
            }
        }
        System.out.println(ans);
    }

    static int DFS(int x, int y) {


        if (dp[x][y] != 0) {
            return dp[x][y];
        }

        dp[x][y] = 1;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (arr[x][y] < arr[nx][ny]) {
                dp[x][y] = Math.max(dp[x][y], DFS(nx, ny) + 1);
            }
        }
        return dp[x][y];
    }
}