import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] dp = new int[N + 1][K + 1];

        System.out.println(combination(N, K, dp));
    }

    static int combination(int n, int k, int[][] dp) {
        if (dp[n][k] > 0) return dp[n][k];

        if (n == k || k == 0) return dp[n][k] = 1;

        return combination(n-1, k-1, dp) + combination(n-1, k, dp);
    }
}