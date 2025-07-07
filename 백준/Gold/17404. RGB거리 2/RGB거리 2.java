
import java.io.*;
import java.util.*;
/**
 *packageName    : _250707
 * fileName       : BOJ_G4_17404_RGB거리2
 * author         : moongi
 * date           : 7/7/25
 * description    :
 *
 */
public class Main {
	static final int INF = 1_000_002;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int[][] cost = new int[N+1][3];

		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());

			cost[i][0] = Integer.parseInt(st.nextToken());
			cost[i][1] = Integer.parseInt(st.nextToken());
			cost[i][2] = Integer.parseInt(st.nextToken());
		}

		int[][] dp = new int[N + 1][3];
		int ans = INF;

		for (int first = 0; first < 3; first++) {

			for (int c = 0; c < 3; c++) {
				dp[1][c] = (c == first) ? cost[1][c] : INF;
			}

			for (int i = 2; i < N + 1; i++) {
				dp[i][0] = cost[i][0] + Math.min(dp[i - 1][1], dp[i - 1][2]);
				dp[i][1] = cost[i][1] + Math.min(dp[i - 1][0], dp[i - 1][2]);
				dp[i][2] = cost[i][2] + Math.min(dp[i - 1][0], dp[i - 1][1]);
			}

			for (int last = 0; last < 3; last++) {
				if (first == last) continue;

				ans = Math.min(ans, dp[N][last]);
			}
		}

		sb.append(ans);
		System.out.println(sb);

	}
}
