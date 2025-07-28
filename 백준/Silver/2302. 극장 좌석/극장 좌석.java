
import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_S1_2302_극장좌석
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		long[] dp = new long[41];

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i < 41; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		int M = Integer.parseInt(br.readLine());
		int ans = 1, prev = 0;

		for (int i = 0; i < M; i++) {
			int seat = Integer.parseInt(br.readLine());

			ans *= dp[seat - prev - 1];
			prev = seat;

		}

		ans *= dp[N - prev];

		System.out.println(ans);
	}

}