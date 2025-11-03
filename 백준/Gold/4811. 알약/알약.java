
import java.util.*;
import java.io.*;
/**
 *packageName    : _251103
 * fileName       : BOJ_G5_4811_알약
 * author         : moongi
 * date           : 11/3/25
 * description    :
 * 1 WH 1
 * 2 WWHH WHWH 1,2 1,3 1100 1010
 * 3 WWWHHH WHWHWH WWHHWH WWHWHH WHWWHH (1,2,3) (1,3,5) (1,2,5) (1,2,4) (1,3,4)
 * 4 (
 */
public class Main {
	static long[][] dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		while (true) {

			int N = Integer.parseInt(br.readLine());

			if (N == 0) break;

			dp = new long[N + 1][N + 1];
			for (int i = 0; i < N + 1; i++) {
				Arrays.fill(dp[i], -1);
			}

			sb.append(solve(N, 0)).append('\n');
		}

		System.out.println(sb);

	}

	static long solve(int w, int h) {
		if (w == 0) return 1;
		if (dp[w][h] != -1)
			return dp[w][h];

		long res = 0;
		if (w > 0) res += solve(w - 1, h + 1);
		if (h > 0) res += solve(w, h - 1);

		return dp[w][h] = res;
	}
}