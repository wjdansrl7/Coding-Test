
import java.io.*;
import java.util.*;

public class Main {
	static int N, M;
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

		int max = -1;
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < M; j++) {
				board[i][j] = str.charAt(j) - '0';

				max = board[i][j] > max ? board[i][j] : max;

			}
		}

		int ans = 0;
		for (int i = 2; i < max + 1; i++) {
			visited = new boolean[N][M];

			for (int j = 1; j < N - 1; j++) {
				for (int k = 1; k < M-1; k++) {
					if (!visited[j][k] && board[j][k] < i) {

						int res = BFS(j, k, i);

						if (res != -1) {
							ans += res;
						}
					}
				}
			}
		}

		System.out.println(ans);

	}

	static int BFS(int x, int y, int depth) {
		ArrayDeque<int[]> q = new ArrayDeque<>();

		int ret = 0;
		boolean flag = true;
		visited[x][y] = true;

		q.offer(new int[] {x, y});

		while (!q.isEmpty()) {
			int[] curr = q.poll();

			ret++;

			if (curr[0] == N - 1 || curr[0] == 0 || curr[1] == M - 1 || curr[1] == 0) {
				if (board[curr[0]][curr[1]] < depth) {
					flag = false;
				}
			}

			for (int d = 0; d < 4; d++) {
				int nx = curr[0] + dx[d];
				int ny = curr[1] + dy[d];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny])
					continue;

				if (board[nx][ny] >= depth)
					continue;

				q.offer(new int[] {nx, ny});
				visited[nx][ny] = true;
			}
		}

		if (!flag) ret = -1;

		return ret;
	}
}
