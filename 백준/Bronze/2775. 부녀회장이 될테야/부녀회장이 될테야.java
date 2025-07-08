
import java.util.*;
import java.io.*;
/**
 *packageName    : _250708
 * fileName       : BOJ_B5_2775_부녀회장
 * author         : moongi
 * date           : 7/8/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int i = 0; i < T; i++) {
			int K = Integer.parseInt(br.readLine());
			int N = Integer.parseInt(br.readLine());

			int[][] dp = new int[K + 1][N + 1];

			for (int j = 0; j < N + 1; j++) {
				dp[0][j] = j;
			}

			for (int j = 1; j < K + 1; j++) {
				for (int k = 1; k < N + 1; k++) {
					for (int l = 1; l < k + 1; l++) {
						dp[j][k] += dp[j-1][l];
					}
				}
			}
			sb.append(dp[K][N]).append('\n');
		}
		System.out.println(sb);
	}
}