import java.util.*;
import java.io.*;

public class Main {
	static int R, C;
	static char[][] board;

	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		board = new char[R][C];
		int rx = 0, ry = 0;

		boolean flag = false;

		ArrayDeque<int[]> q = new ArrayDeque<>();
		ArrayDeque<int[]> next = new ArrayDeque<>();
		ArrayDeque<int[]> waterQ = new ArrayDeque<>();
		boolean[][] visited = new boolean[R][C];

		for (int i = 0; i < R; i++) {
			String str = br.readLine();
			for (int j = 0; j < C; j++) {
				board[i][j] = str.charAt(j);

				if (board[i][j] == 'L') {
					if (!flag) {
						q.offer(new int[] {i, j});
						visited[i][j] = true;
						flag = true;
					} else {
						rx = i;
						ry = j;
					}
				}

				if (board[i][j] != 'X') {
					waterQ.offer(new int[] {i, j});
				}
			}
		}
		
		int days = 0;
		flag = false;

		while (true) {
			next = new ArrayDeque<>();
			// next.clear()으로 할 경우, 참조는 그대로 유지하므로, q도 같이 빈 상태가 된다.

			while (!q.isEmpty()) {
				int[] p = q.poll();
				if (p[0] == rx && p[1] == ry) {
					flag = true;
					break;
				}

				for (int d = 0; d < 4; d++) {
					int nx = p[0] + dx[d];
					int ny = p[1] + dy[d];

					if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny])
						continue;

					visited[nx][ny] = true;


					if (board[nx][ny] == 'X') {
						next.offer(new int[] {nx, ny});
						continue;
					}

					q.offer(new int[] {nx, ny});
				}
			}

			if (flag)
				break;
			q = next;


			int size = waterQ.size();

			for (int i = 0; i < size; i++) {
				int[] p = waterQ.poll();
				for (int d = 0; d < 4; d++) {
					int nx = p[0] + dx[d];
					int ny = p[1] + dy[d];

					if (nx < 0 || nx >= R || ny < 0 || ny >= C)
						continue;


					if (board[nx][ny] == 'X') {
						board[nx][ny] = '.';
						waterQ.offer(new int[] {nx, ny});
					}

				}
			}
			days++;
		}

		System.out.println(days);

	}
}