
import java.util.*;
import java.io.*;
/**
 *packageName    : _260315
 * fileName       : BOJ_G5_2225_합분해
 * author         : moongi
 * date           : 3/15/26
 * description    :
 *
 * dp[N][K] = dp[N-1][K] + dp[N][K-1]
 *
 * 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
 *
 */
public class Main {
	static final int MOD = 1_000_000_000;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		int[][] dp = new int[N + 1][K + 1];

		for (int i = 0; i < N + 1; i++) {
			dp[i][0] = 0;
			dp[i][1] = 1;
		}

		// N이 1일 경우 만들 수 있는 갯수는 K개 (0을 몇 개를 두느냐에 따라 갯수가 달라지기 때문에)
		for (int i = 0; i < K + 1; i++) {
			dp[1][i] = i;
		}

		for (int i = 2; i < N + 1; i++) {
			for (int j = 2; j < K + 1; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
		System.out.println(dp[N][K]);
	}
}