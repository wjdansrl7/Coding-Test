import java.util.*;
import java.io.*;

public class Main {

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static List<Point> students, teachers;
	static int N;
	static int[][] board;

	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		students = new ArrayList<>();
		teachers = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			String[] str = br.readLine().split(" ");
			for (int j = 0; j < N; j++) {
				if (str[j].equals("T")) {
					board[i][j] = 1;
					teachers.add(new Point(i, j));
				} else if (str[j].equals("S")) {
					board[i][j] = 2;
					students.add(new Point(i, j));
				} else {
					board[i][j] = 0;
				}
			}
		}

		combination(0);

		System.out.println("NO");
	}

	static boolean isValid(int x, int y) {
		if (x < 0 || x >= N || y < 0 || y >= N) return false;

		return true;
	}

	static void checkPoint() {

		ArrayDeque<Point> q = new ArrayDeque<>();

		for (int i = 0; i < teachers.size(); i++) {
			q.offer(teachers.get(i));
		}

		while (!q.isEmpty()) {

			Point p = q.poll();

			for (int d = 0; d < 4; d++) {
				int nx = p.x + dx[d];
				int ny = p.y + dy[d];

				while (isValid(nx, ny)) {

					if (board[nx][ny] == 3) {
						// 벽에 마주치면 더이상 움직이지 않는다.
						break;
					} else if (board[nx][ny] == 2) {
						// 감시를 피하지 못했다.
						return;
					}

					nx += dx[d];
					ny += dy[d];

				}
			}
		}

		System.out.println("YES");
		System.exit(0);
	}

	static void combination(int cnt) {

		if (cnt == 3) {
			checkPoint();
			return;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (board[i][j] != 0) continue;

				board[i][j] = 3;
				combination(cnt+1);
				board[i][j] = 0;
			}
		}
	}
}
