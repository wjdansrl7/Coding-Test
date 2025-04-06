
import java.io.*;
import java.util.*;

public class Main {
	static int N, M, res;
	static int[][] board;
	static boolean[][] visited;

	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		board = new int[N][M];
		visited = new boolean[N][M];
		res = 0;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = true;
				dfs(i, j, board[i][j], 1);
				visited[i][j] = false;
			}
		}

		System.out.println(res);
	}

	static void dfs(int x, int y, int sum, int cnt) {

		if (cnt == 4) {
			res = sum > res ? sum : res;
			return;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (!visited[nx][ny]) {
				if (cnt == 2) {
					visited[nx][ny] = true;
					dfs(x, y, sum + board[nx][ny], cnt + 1);
					visited[nx][ny] = false;
				}

				visited[nx][ny] = true;
				dfs(nx, ny, sum + board[nx][ny], cnt + 1);
				visited[nx][ny] = false;
			}
		}
	}
}
