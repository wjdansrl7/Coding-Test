import java.util.*;
import java.io.*;

public class Main {
	static int N, M, K, res = -Integer.MAX_VALUE;
	static int[][] board;
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		board = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int[][] ret = new int[K][2];
		boolean[][] visited = new boolean[N][M];
		combination(0, visited, ret);

		System.out.println(res);
	}

	static void combination(int cnt, boolean[][] visited, int[][] ret) {

		if (!isRange(visited, ret)) return;

		if (cnt == K) {
			int tmp = getScore(ret);
			res = tmp > res ? tmp : res;

			return;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					ret[cnt][0] = i;
					ret[cnt][1] = j;
					combination(cnt+1, visited, ret);
					visited[i][j] = false;
				}
			}
		}
	}

	static boolean isRange(boolean[][] visited, int[][] ret) {
		for (int i = 0; i < K; i++) {

			int x = ret[i][0];
			int y = ret[i][1];

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

				if (visited[nx][ny]) return false;
			}
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