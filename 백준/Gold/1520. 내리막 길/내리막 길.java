
import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_G3_1520_내리막길
 * author         : moongi
 * date           : 7/29/25
 * description    :
 * DP + DFS
 */
public class Main {
	static int M, N;
	static int[][] board, dp;
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());

		board = new int[M + 1][N + 1];
		dp = new int[M + 1][N + 1];

		for (int i = 0; i < M + 1; i++) {
			Arrays.fill(dp[i], -1);
		}

		for (int i = 1; i < M + 1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < N + 1; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

        System.out.println(DFS(1, 1));



	}

	static int DFS(int x, int y) {
		if (x == M && y == N) {
			return 1;
		}

		if (dp[x][y] != -1) return dp[x][y];

		dp[x][y] = 0;

		for (int d = 0; d < 4; d++) {

			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 1 || nx > M || ny < 1 || ny > N) continue;

			if (board[x][y] > board[nx][ny]) {
				dp[x][y] += DFS(nx, ny);
			}

		}

		return dp[x][y];
	}
}