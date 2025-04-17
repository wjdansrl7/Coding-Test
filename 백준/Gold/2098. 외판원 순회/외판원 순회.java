import java.io.*;
import java.util.*;

public class Main {
	static int N;
	static final int INF = 16_000_000;
	static int[][] w, dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		w = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				w[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dp = new int[N][(1 << N) - 1];
		for (int i = 0; i < N; i++) Arrays.fill(dp[i], -1);

		System.out.println(dfs(0, 1));
	}

	static int dfs(int now, int visit) {
		// 모든 경로를 방문한 경우
		if (visit == (1 << N) - 1) {
            if (w[now][0] == 0) return INF;
			return w[now][0];
 		}

		if (dp[now][visit] != -1)
			return dp[now][visit];

		dp[now][visit] = INF;

		for (int i = 0; i < N; i++) {
			if ((visit & (1 << i)) == 0 && w[now][i] != 0) {
				dp[now][visit] = Math.min(dfs(i, visit | (1 << i)) + w[now][i],
				dp[now][visit]);
			}
		}
		return dp[now][visit];
	}
}