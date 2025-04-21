import java.util.*;
import java.io.*;

public class Main {
	static int[] arr = {1, 7, 4, 2, 0, 8};
	static long[] dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = null;
		int T = Integer.parseInt(br.readLine());
		int N;
		dp = new long[101];

		Arrays.fill(dp, Long.MAX_VALUE);

		dp[2] = 1;
		dp[3] = 7;
		dp[4] = 4;
		dp[5] = 2;
		dp[6] = 6;
		dp[7] = 8;
		dp[8] = 10;

		for (int i = 9; i < 101; i++) {
			for (int j = 2; j < 8; j++) {
				String tmp = String.valueOf(dp[i - j]) + String.valueOf(arr[j - 2]);
				dp[i] = Math.min(Long.parseLong(tmp), dp[i]);
			}
		}

		// 현재 스틱은 정렬된 상태로 존재한다.

		for (int tc = 0; tc < T; tc++) {
			sb = new StringBuilder();

			N = Integer.parseInt(br.readLine());

			sb.append(dp[N]).append(" ");
			if (N % 2 == 0) {
				sb.append(findMax(N / 2));
			} else {
				sb.append("7").append(findMax((N - 3) / 2));
			}
			System.out.println(sb);
		}
	}

	static String findMax(int N) {
		StringBuilder sb = new StringBuilder();
		// 가장 큰 자리수를 만드는게 가장 큰 수를 만드는 것이다.
		for (int i = 0; i < N; i++) {
			sb.append("1");
		}

		return sb.toString();
	}
}