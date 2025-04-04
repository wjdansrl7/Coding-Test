
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());

		int[][] arr = new int[N + 1][N + 1];
		int[][] dp = new int[N + 1][N + 1];

		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < N + 1; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
			}
		}

		int res = Integer.MIN_VALUE, tmp = 0;
		for (int k = 1; k <= N; k++) {
			for (int i = k; i <= N; i++) {
				for (int j = k; j <= N; j++) {
					tmp = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
					res = tmp > res ? tmp : res;
				}
			}
		}

		System.out.println(res);

	}
}

