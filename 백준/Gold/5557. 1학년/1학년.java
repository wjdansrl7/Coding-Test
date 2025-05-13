
import java.util.*;
import java.io.*;

/**
 *packageName    : _250513
 * fileName       : BOJ_G5_5557_1학년
 * author         : moongi
 * date           : 5/13/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		long[][] dp = new long[N][21];

		// 구하고 하는 값
		// dp[N-2][arr[N-1]

		dp[0][arr[0]] = 1; // 초기 경우의 수를 1로 저장

		int plus, minus;

		for (int i = 1; i < N-1; i++) {

			for (int j = 0; j <= 20; j++) {
				if (dp[i - 1][j] != 0) {
					plus = j + arr[i];
					minus = j - arr[i];

					if (plus >= 0 && plus <= 20) {
						dp[i][plus] += dp[i - 1][j];
					}

					if (minus >= 0 && minus <= 20) {
						dp[i][minus] += dp[i - 1][j];
					}
				}
			}
		}

		System.out.println(dp[N - 2][arr[N - 1]]);

	}
}