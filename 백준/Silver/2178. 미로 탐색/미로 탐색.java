
import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_S1_2178_미로탐색
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	static int N, M;
	static int[][] board;
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		board = new int[N + 1][M + 1];

		for (int i = 1; i < N + 1; i++) {

			String str = br.readLine();
			for (int j = 1; j < M + 1; j++) {

				board[i][j] = str.charAt(j - 1) - '0';
			}
		}

		System.out.println(BFS(1, 1));
	}

	static int BFS(int x, int y) {

		boolean[][] visited = new boolean[N + 1][M + 1];
		ArrayDeque<int[]> q = new ArrayDeque<>();

		q.offer(new int[] {x, y, 1});
		visited[x][y] = true;

		while (!q.isEmpty()) {

			int[] p = q.poll();

			if (p[0] == N && p[1] == M) {
				return p[2];
			}

			for (int d = 0; d < 4; d++) {
				int nx = p[0] + dx[d];
				int ny = p[1] + dy[d];

				if (!isValid(nx, ny) || visited[nx][ny]) continue;

				visited[nx][ny] = true;
				q.offer(new int[] {nx, ny, p[2] + 1});
			}

		}

		return -1;

	}

	static boolean isValid(int x, int y) {
		if (x < 1 || x > N || y < 1 || y > M || board[x][y] == 0) return false;

		return true;
	}
}