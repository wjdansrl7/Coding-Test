
import java.io.*;
import java.util.ArrayDeque;

public class Main {
	static int N;
	static char[][] arr;

	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static class Log {
		Point p;
		int dir;
		int cnt;
		public Log(Point p, int dir, int cnt) {
			this.p = p;
			this.dir = dir;
			this.cnt = cnt;
		}
	}

	static Point[] points;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		points = new Point[3];
		arr = new char[N][N];

		int idx = 0;
		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < N; j++) {
				arr[i][j] = str.charAt(j);

				if (arr[i][j] == 'B') {
					points[idx++] = new Point(i, j);
				}
			}
		}

		int dir;
		if (points[0].x == points[1].x) dir = 0;
		else dir = 1;

		System.out.println(BFS(dir));

	}

	static int BFS(int dir) {

		ArrayDeque<Log> q = new ArrayDeque<>();
		boolean[][][] visited = new boolean[N][N][2];

		q.offer(new Log(points[1], dir, 0));
		visited[points[1].x][points[1].y][dir] = true;

		while (!q.isEmpty()) {

			Log curr = q.poll();

			if (curr.dir == 0) {
				if (curr.p.y - 1 >= 0 && curr.p.y + 1 < N &&
					arr[curr.p.x][curr.p.y-1]=='E' && arr[curr.p.x][curr.p.y]=='E' && arr[curr.p.x][curr.p.y+1]=='E') {
					return curr.cnt;
				}
			} else {
				if (curr.p.x - 1 >= 0 && curr.p.x + 1 < N &&
					arr[curr.p.x-1][curr.p.y]=='E' && arr[curr.p.x][curr.p.y]=='E' && arr[curr.p.x+1][curr.p.y]=='E') {
					return curr.cnt;
				}
			}


			for (int d = 0; d < 4; d++) {
				int nx = curr.p.x + dx[d];
				int ny = curr.p.y + dy[d];

				if (isValid(nx, ny, curr.dir, d) && !visited[nx][ny][curr.dir]) {
					visited[nx][ny][curr.dir] = true;
					q.offer(new Log(new Point(nx, ny), curr.dir, curr.cnt + 1));
				}
			}

			if (isTurn(curr.p.x, curr.p.y)) {

				if (curr.dir == 0 && !visited[curr.p.x][curr.p.y][1]) {
					visited[curr.p.x][curr.p.y][1] = true;
					q.offer(new Log(new Point(curr.p.x, curr.p.y), 1, curr.cnt + 1));
				} else if (curr.dir == 1 && !visited[curr.p.x][curr.p.y][0]) {
					visited[curr.p.x][curr.p.y][0] = true;
					q.offer(new Log(new Point(curr.p.x, curr.p.y), 0, curr.cnt + 1));
				}
			}
		}
		return 0;
	}

	static boolean isTurn(int x, int y) {
		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i < 0 || i >= N || j < 0 || j >= N) return false;

				if (arr[i][j] == '1') return false;
			}
		}

		return true;
	}

	static boolean isValid(int x, int y, int curDir, int d) {
		if (curDir == 0) {
			// not valid range
			if (x < 0 || x >= N || y - 1 < 0 || y + 1 >= N) return false;

			// updown
			if (d < 2) {
				// not Log
				if (arr[x][y] == '1' || arr[x][y-1] == '1' || arr[x][y+1] == '1') return false;
			} else {
				if (arr[x][y] == '1' || arr[x][y-1] == '1' || arr[x][y+1] == '1') return false;
			}
		} else {
			if (x - 1 < 0 || x + 1 >= N  || y < 0 || y >= N) return false;

			if (d < 2) {
				if (arr[x][y] == '1' || arr[x-1][y] == '1' || arr[x+1][y] == '1') return false;
			} else {
				if (arr[x][y] == '1' || arr[x-1][y] == '1' || arr[x+1][y] == '1') return false;
			}
		}

		return true;

	}
}
