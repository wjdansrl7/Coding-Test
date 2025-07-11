
import java.util.*;
import java.io.*;
/**
 *packageName    : _250711
 * fileName       : BOJ_B1_2748_피보나치수2
 * author         : moongi
 * date           : 7/11/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		long[] dp = new long[N + 1];
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i < N + 1; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		System.out.println(dp[N]);
	}
}
