
import java.util.*;
import java.io.*;
/**
 *packageName    : _250709
 * fileName       : BOJ_S$_2839_설탕배달
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int[] dp = new int[5001];

		Arrays.fill(dp, 1_000_000);

		dp[0] = 0;
		dp[3] = 1;
		dp[5] = 1;

		for (int i = 6; i < N + 1; i++) {
			dp[i] = Math.min(dp[i-3], dp[i-5]) + 1;
		}

		if (dp[N] >= 1_000_000) System.out.println(-1);
		else System.out.println(dp[N]);
	}
}