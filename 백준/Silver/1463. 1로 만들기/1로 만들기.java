
import java.util.*;
import java.io.*;
/**
 *packageName    : _260405
 * fileName       : BOJ_S3_1463_1로만들기
 * author         : moongi
 * date           : 4/5/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		if (N < 3) {
			System.out.println(N - 1);
			return;
		}

		int[] dp = new int[N + 1];

		dp[1] = 0;
		dp[2] = 1;

		for (int i = 3; i < N + 1; i++) {
			int v1 = i % 3 == 0 ? dp[i / 3] : Integer.MAX_VALUE;
			int v2 = i % 2 == 0 ? dp[i / 2] : Integer.MAX_VALUE;

			dp[i] = Math.min(Math.min(v1, v2), dp[i - 1]) + 1;
		}

		System.out.println(dp[N]);
	}
}