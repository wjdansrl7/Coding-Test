
import java.io.*;
import java.util.*;
/**
 *packageName    : _250731
 * fileName       : BOJ_G3_2206_벽부수고이동하기
 * author         : moongi
 * date           : 7/31/25
 * description    :
 */
public class Main {
	static int N, M, ans;
	static int[][] board;

	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};

	static class Node {
		int x, y, cnt;
		boolean flag;

		public Node(int x, int y, int cnt, boolean flag) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
			this.flag = flag;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		board = new int[N + 1][M + 1];
		ans = Integer.MAX_VALUE;

		for (int i = 1; i < N + 1; i++) {
			String str = br.readLine();

			for (int j = 1; j < M + 1; j++) {
				board[i][j] = str.charAt(j - 1) - '0';
			}
		}

		System.out.println(BFS());
	}

	static int BFS() {

		int[][][] visited = new int[2][N + 1][M + 1];

		int ans = Integer.MAX_VALUE;
		// 0, n, m : 벽 X
		// 1, n, m : 벽 O

		ArrayDeque<int[]> q = new ArrayDeque<>();

		q.offer(new int[] {0, 1, 1});
		visited[0][1][1] = 1;

		while (!q.isEmpty()) {

			int[] p = q.poll();

			if (p[1] == N && p[2] == M) {

				return visited[p[0]][p[1]][p[2]];
			}

			for (int d = 0; d < 4; d++) {
				int nx = p[1] + dx[d];
				int ny = p[2] + dy[d];

				if (!isValid(nx, ny)) continue;

				if (board[nx][ny] == 0) {

					if (visited[p[0]][nx][ny] == 0) {
						visited[p[0]][nx][ny] = visited[p[0]][p[1]][p[2]] + 1;
						q.offer(new int[] {p[0], nx, ny});
					}

				} else {

					if (p[0] == 0) {

						if (visited[1][nx][ny] == 0) {
							visited[1][nx][ny] = visited[p[0]][p[1]][p[2]] + 1;
							q.offer(new int[] {1, nx, ny});
						}
					}
				}
			}
		}

		return -1;
	}

	static boolean isValid(int x, int y) {

		if (x < 1 || x > N || y < 1 || y > M) return false;

		return true;
	}
}