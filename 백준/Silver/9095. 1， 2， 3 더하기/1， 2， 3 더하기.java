
import java.io.*;
import java.util.*;
/**
 *packageName    : _250709
 * fileName       : BOJ_S3_9095_123더하기
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int[] dp = new int[12];
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i < 12; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			int N = Integer.parseInt(br.readLine());

			sb.append(dp[N]).append('\n');
		}
		System.out.println(sb);
	}
}