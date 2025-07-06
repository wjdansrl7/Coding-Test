
import java.io.*;
import java.util.*;

/**
 *packageName    : _250706
 * fileName       : BOJ_S1_1890_점프
 * author         : moongi
 * date           : 7/6/25
 * description    :
 */
public class Main {
	static int ans, N;
	static int[][] arr;
	static long[][] dp;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		ans = 0;

		arr = new int[N][N];
		dp = new long[N][N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				dp[i][j] = -1;

			}
		}

		long ans = DFS(0, 0);

		sb.append(ans);
		System.out.println(sb);
	}

	static long DFS(int x, int y) {

		if (x == N-1 && y == N-1) {
			return 1;
		}

		if (dp[x][y] != -1) {
			return dp[x][y];
		}

		dp[x][y] = 0;

		int nx = x + arr[x][y];

		if (nx >= 0 && nx < N && y >= 0 && y < N) dp[x][y] += DFS(nx, y);

		int ny = y + arr[x][y];

		if (x >= 0 && x < N && ny >= 0 && ny < N) dp[x][y] += DFS(x, ny);

		return dp[x][y];
	}
}