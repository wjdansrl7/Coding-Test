
import java.io.*;
import java.util.*;
/**
 *packageName    : _250711
 * fileName       : BOJ_G5_12865_평범한배낭
 * author         : moongi
 * date           : 7/11/25
 * description    :
 */
public class Main {
	static class Thing {
		int W, V;

		public Thing(int w, int v) {
			W = w;
			V = v;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		Thing[] things = new Thing[N + 1];

		int W, V;
		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());
			W = Integer.parseInt(st.nextToken());
			V = Integer.parseInt(st.nextToken());

			things[i] = new Thing(W, V);
		}

		// 담은 물건의 개수, 무게
		int[][] dp = new int[N+1][100_001];

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < K + 1; j++) {

				if (j >= things[i].W) {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - things[i].W] + things[i].V);
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		
		System.out.println(dp[N][K]);
	}
}