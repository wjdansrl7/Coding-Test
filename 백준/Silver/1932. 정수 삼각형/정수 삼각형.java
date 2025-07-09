
import java.io.*;
import java.util.*;

/**
 *packageName    : _250709
 * fileName       : BOJ_S1_1932_정수삼각형
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		int[][] arr = new int[N + 1][N + 1];

		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());

			int j = 1;
			while(st.hasMoreTokens()) {
				arr[i][j++] = Integer.parseInt(st.nextToken());
			}
		}

		int[][] dp = new int[N + 1][N + 1];

		dp[1][1] = arr[1][1];

		for (int i = 2; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < N + 1; i++) {
			if (dp[N][i] > ans)
				ans = dp[N][i];
		}

		System.out.println(ans);
	}
}