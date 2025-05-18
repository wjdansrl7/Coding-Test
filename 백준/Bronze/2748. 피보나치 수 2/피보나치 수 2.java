
import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 *packageName    : _250518
 * fileName       : BOJ_B1_2748_피보나치수2
 * author         : moongi
 * date           : 5/18/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(br.readLine());
		long[] dp = new long[n+1];

		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		
		sb.append(dp[n]);
		System.out.println(sb);
	}
}