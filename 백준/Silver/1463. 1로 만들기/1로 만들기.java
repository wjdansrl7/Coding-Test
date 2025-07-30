import java.util.*;
import java.io.*;

/**
 *packageName    : _250730
 * fileName       : BOJ_S3_1463_1로만들기
 * author         : moongi
 * date           : 7/30/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int[] dp = new int[N + 1];

		dp[1] = 0;

		if (N <= 1) {
			System.out.println(dp[N]);
			return;
		}

		for (int i = 2; i < N + 1; i++) {

			int tmp1 = Integer.MAX_VALUE, tmp2 =Integer.MAX_VALUE;
			if (i % 2 == 0) {
				tmp1 = dp[i / 2];
			}

			if (i % 3 == 0) {
				tmp2 = dp[i / 3];
			}

			dp[i] = Math.min(Math.min(tmp1, tmp2), dp[i - 1]) + 1;
		}

		System.out.println(dp[N]);
	}
}