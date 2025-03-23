
import java.io.*;
import java.util.*;

public class Main {
	static int N, M, K, res = Integer.MIN_VALUE;
	static int[][] board;
	static boolean[][] visited;
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		board = new int[N][M];
		visited = new boolean[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dfs(0, 0, 0, 0);

		System.out.println(res);
	}

	static void dfs(int x, int y, int cnt, int sum) {

		if (cnt == K) {
			res = sum > res ? sum : res;
			return;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j]) {
					if (isRange(i, j)) {
						visited[i][j] = true;
						dfs(i, j, cnt + 1, sum + board[i][j]);
						visited[i][j] = false;
					}
				}
			}
		}
	}

	static boolean isRange(int x, int y) {

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (visited[nx][ny])
				return false;
		}

		return true;
	}

	static int getScore(int[][] ret) {
		int score = 0;
		for (int i = 0; i < K; i++) {
			score += board[ret[i][0]][ret[i][1]];
		}

		return score;
	}
}
