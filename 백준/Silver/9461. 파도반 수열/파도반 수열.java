import java.io.*;
import java.util.*;

/**
 *packageName    : _250709
 * fileName       : BOJ_S3_9461_파도반수열
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		long[] dp = new long[101];

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;

		for (int i = 6; i < 101; i++) {
			dp[i] = dp[i-5] + dp[i-1];
		}

		while (T-- > 0) {
			int N = Integer.parseInt(br.readLine());

			sb.append(dp[N]).append('\n');
		}

		System.out.println(sb);
	}
}
