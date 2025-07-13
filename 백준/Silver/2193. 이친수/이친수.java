import java.util.*;
import java.io.*;
/**
 *packageName    : _250713
 * fileName       : BOJ_S3_2193_이친수
 * author         : moongi
 * date           : 7/13/25
 * description    :
 * 1
 * 10
 * 100 101
 * 1000, 1001, 1010
 * 10000, 10001, 10010, 10101, 10100
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		// 자리수, 자릿값
		long[][] dp = new long[N+1][2];
        
        if (N == 1) {
			System.out.println(1);
			return;
		}

		dp[1][1] = 1;
		dp[2][0] = 1;

		// 이전 자리가 1이었으면 다음 자리에 올 수 있는 자리는 0만 올 수 있음.
		// 이전 자리가 0이었으면 0 또는 1 둘 다 올 수 있음

		for (int i = 3; i < N + 1; i++) {
			dp[i][1] = dp[i - 1][0];

			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		}

		System.out.println(dp[N][0] + dp[N][1]);

	}
}