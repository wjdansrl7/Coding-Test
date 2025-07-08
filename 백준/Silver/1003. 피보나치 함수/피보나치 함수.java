
import java.io.*;
import java.util.*;
/**
 *packageName    : _250708
 * fileName       : BOJ_S3_1003_피보나치함수
 * author         : moongi
 * date           : 7/8/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int i = 0; i < T; i++) {
			int N = Integer.parseInt(br.readLine());

			if (N == 0) {
				sb.append(1 + " " + 0).append('\n');
				continue;
			}

			int[][] dp = new int[N + 1][2];
			dp[0][0] = 1;
			dp[1][1] = 1;

			for (int j = 2; j < N + 1; j++) {
				dp[j][0] = dp[j - 1][0] + dp[j - 2][0];
				dp[j][1] = dp[j - 1][1] + dp[j - 2][1];
			}


			sb.append(dp[N][0] + " " + dp[N][1]).append('\n');
		}
		System.out.println(sb);
	}
}