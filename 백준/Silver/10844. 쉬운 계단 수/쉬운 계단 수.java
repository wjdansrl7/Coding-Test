import java.io.*;
import java.util.*;

/**
 *packageName    : _250713
 * fileName       : BOJ_S1_10844_쉬운계단수
 * author         : moongi
 * date           : 7/13/25
 * description    :
 * 소수 문제를 풀 경우 자리수를 왼쪽에서 오른쪽으로 순서대로 잡고
 * 자연수 같은 경우, 오른쪽에서 왼쪽으로 잡는다.
 * 45656 일 경우, 1번째 수는 6, 6번째 수는 4
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		final long INF = 1_000_000_000;

		long[][] dp = new long[N+1][10];

		// 한 자리수에서 나올 수 있는 자릿값은 한 가지만 있다.
		for (int i = 1; i < 10; i++) {
			dp[1][i] = 1;
		}

		for (int i = 2; i < N + 1; i++) {

			for (int j = 0; j < 10; j++) {

				// 자릿값이 0인 경우는 다음 수에는 1밖에 못온다.
				if (j == 0) {
					dp[i][0] = dp[i-1][1] % INF;
				} else if (j == 9) {
					dp[i][9] = dp[i - 1][8] % INF;
				} else {
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % INF;
				}
			}
		}

		long ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += dp[N][i];
		}

		System.out.println(ans % INF);

	}
}
