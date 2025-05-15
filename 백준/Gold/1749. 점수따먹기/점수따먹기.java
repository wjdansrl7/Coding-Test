import java.util.*;
import java.io.*;

/**
 *packageName    : _250515
 * fileName       : BOJ_G4_1719_점수따먹기
 * author         : moongi
 * date           : 5/15/25
 * description    :
 */
public class Main {
	static int N, M;
	static int[][] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N + 1][M + 1];

		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < M +1; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int[][] dp = new int[N + 1][M + 1];
		int max = Integer.MIN_VALUE;

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];

				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				for (int k = 1; k <= i; k++) {
					for (int l = 1; l <= j; l++) {
						int tmp = dp[i][j] - dp[k - 1][j] - dp[i][l - 1] + dp[k - 1][l - 1];

						if (tmp > max) {
							max = tmp;
						}
					}
				}
			}
		}

		System.out.println(max);
	}
}