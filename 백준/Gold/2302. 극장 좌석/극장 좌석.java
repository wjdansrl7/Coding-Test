
import java.io.*;

/**
 *packageName    : _250718
 * fileName       : BOJ_G5_2302_극장좌석
 * author         : moongi
 * date           : 7/18/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int ans = 1;
		int[] dp = new int[41];

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i < N + 1; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		int M = Integer.parseInt(br.readLine());

		int beforeSeat = 0;
		for (int i = 0; i < M; i++) {
			int fix = Integer.parseInt(br.readLine());

			ans *= dp[fix - beforeSeat - 1];
			beforeSeat = fix;
		}

		ans *= dp[N - beforeSeat]; // 마지막 vip 좌석 다음 좌석에서 끝 좌석까지의 경우의 수

		sb.append(ans);
		System.out.println(sb);

	}
}