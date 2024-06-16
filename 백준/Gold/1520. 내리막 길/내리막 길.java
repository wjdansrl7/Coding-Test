import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static int[][] arr, dp;
    static int[] dx = {-1,0,1,0}, dy = {0, 1, 0, -1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        dp = new int[m][n];
        arr = new int[m][n];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }

        DFS(0, 0);

        System.out.println(dp[0][0]);
    }

    private static int DFS(int x, int y) {
        if (x == m-1 && y == n-1) return 1;

        if (dp[x][y] != -1) return dp[x][y];

        dp[x][y] = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (arr[nx][ny] < arr[x][y]) dp[x][y] += DFS(nx, ny);
        }
        return dp[x][y];
    }
}