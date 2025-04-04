
import java.util.*;
import java.io.*;

public class Main {
	static int R, C, K, W;
	static int[][] board, temp;

	static int[] dx = {0, 0, 0, -1, 1};
	static int[] dy = {0, 1, -1, 0, 0}; // 오른쪽, 왼쪽, 위, 아래

	static class Point {
		int x, y, dir;

		public Point(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}

	static Point[] checks, conditioners;
	static int idx, cIdx;
	static boolean[][][] walls;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		board = new int[R + 1][C + 1]; // 방의 크기
		temp = new int[R + 1][C + 1]; // 초기 온도는 0도이다.

		idx = 0; // 조사해야하는 칸의 개수
		cIdx = 0; // 온풍기의 개수
		checks = new Point[400];
		conditioners = new Point[400];

		for (int i = 1; i < R + 1; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j < C + 1; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());

				// 조사해야하는 칸의 위치 정보 저장
				if (board[i][j] == 5) {
					checks[idx++] = new Point(i, j, 0);
				}

				// 온풍기의 위치 저장
				if (board[i][j] > 0 && board[i][j] < 5) {
					conditioners[cIdx++] = new Point(i, j, board[i][j]);
				}
			}
		}

		walls = new boolean[2][R + 1][C + 1];
		W = Integer.parseInt(br.readLine());

		// 벽의 위치 정보 저장
		int x, y, d; // 0 일 경우, 해당 위치에 위에, 1일 경우, 오른쪽
		for (int i = 0; i < W; i++) {
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			walls[d][x][y] = true;
		}
		int choco = 0;

		do {
			increase();
			control();
			decrease();
			choco++;

			if (choco > 100) {
				break;
			}

		} while (!test());

		System.out.println(choco);
	}

	// 1. 온풍기에서 바람이 나온다. -> 온풍기의 위치를 알아야 한다.
	// 벽의 위치에 영향을 받으므로 벽의 위치도 고려해줘야 한다.
	static void increase() {
		for (int i = 0; i < cIdx; i++) {
			Point curr = conditioners[i]; // 현재 온풍기 위치

			int x = curr.x;
			int y = curr.y;
			int dir = curr.dir;

			moveWind(x, y, dir);
		}
	}

	static void moveWind(int x, int y, int dir) {
		ArrayDeque<int[]> q = new ArrayDeque<>();
		boolean[][] visited = new boolean[R+1][C+1];

		if (dir == 1) {
			if (!isValid(x, y) && !walls[1][x][y] && !isValid(x, y + 1)) {

				q.offer(new int[] {x, y + 1, 5});
				visited[x][y + 1] = true;
			}
		} else if (dir == 2) {
			if (!isValid(x, y-1) && !walls[1][x][y-1]) {
				q.offer(new int[] {x, y - 1, 5});
				visited[x][y - 1] = true;
			}
		} else if (dir == 3) {
			if (!isValid(x, y) && !walls[0][x][y] && !isValid(x-1, y)) {
				q.offer(new int[] {x - 1, y, 5});
				visited[x-1][y] = true;
			}
		} else if (dir == 4) {
			if (!isValid(x+1,y) && !walls[0][x+1][y] && !isValid(x+1, y)) {
				q.offer(new int[] {x + 1, y, 5});
				visited[x+1][y] = true;
			}
		}

		while (!q.isEmpty()) {
			int[] p = q.poll();
			int xx = p[0];
			int yy = p[1];

			if (p[2] == 0) continue;

			// 해당 위치에 온도를 증가
			temp[xx][yy] += p[2];

			if (dir == 1) {
				if (!isValid(xx, yy) &&!walls[0][xx][yy] &&
					!isValid(xx-1, yy) &&!walls[1][xx - 1][yy] &&
					!isValid(xx-1, yy+1) && !visited[xx - 1][yy + 1]) {

					q.offer(new int[] {xx - 1, yy + 1, p[2] - 1});
					visited[xx - 1][yy + 1] = true;
				}
				if (!isValid(xx, yy) && !walls[1][xx][yy] &&
					!isValid(xx, yy+1) && !visited[xx][yy + 1]) {

					q.offer(new int[] {xx, yy + 1, p[2] - 1});
					visited[xx][yy+1] = true;
				}
				if (!isValid(xx+1, yy) && !walls[1][xx + 1][yy] &&
					!isValid(xx+1, yy) && !walls[0][xx + 1][yy] &&
					!isValid(xx+1, yy+1) && !visited[xx + 1][yy + 1]) {

					q.offer(new int[] {xx + 1, yy + 1, p[2] - 1});
					visited[xx+1][yy+1] = true;
				}
			} else if (dir == 2) {
				if (!isValid(xx, yy) && !walls[0][xx][yy] &&
					!isValid(xx-1,yy-1) && !walls[1][xx - 1][yy-1] &&
					!isValid(xx-1, yy-1) && !visited[xx - 1][yy - 1]) {

					q.offer(new int[] {xx - 1, yy - 1, p[2] - 1});
					visited[xx - 1][yy - 1] = true;
				}
				if (!isValid(xx, yy-1) && !walls[1][xx][yy - 1] &&
					!isValid(xx, yy-1) && !visited[xx][yy - 1]) {
					q.offer(new int[] {xx, yy - 1, p[2] - 1});
					visited[xx][yy - 1] = true;
				}
				if (!isValid(xx+1, yy) && !walls[0][xx + 1][yy] &&
					!isValid(xx+1, yy-1) && !walls[1][xx + 1][yy - 1] &&
					!isValid(xx+1, yy-1) && !visited[xx + 1][yy - 1]) {

					q.offer(new int[] {xx + 1, yy - 1, p[2] - 1});
					visited[xx + 1][yy - 1] = true;
				}
			} else if (dir == 3) {
				if (!isValid(xx, yy-1) && !walls[0][xx][yy - 1] &&
					!isValid(xx, yy-1) && !walls[1][xx][yy - 1] &&
					!isValid(xx-1, yy-1) && !visited[xx - 1][yy - 1]) {

					q.offer(new int[] {xx - 1, yy - 1, p[2] - 1});
					visited[xx - 1][yy - 1] = true;
				}
				if (!isValid(xx, yy) && !walls[0][xx][yy] &&
					!isValid(xx-1, yy) && !visited[xx-1][yy]) {
					q.offer(new int[] {xx - 1, yy, p[2] - 1});
					visited[xx - 1][yy] = true;
				}
				if (!isValid(xx, yy) && !walls[1][xx][yy] &&
					!isValid(xx, yy+1) && !walls[0][xx][yy + 1] &&
					!isValid(xx-1,yy+1) && !visited[xx - 1][yy + 1]) {
					q.offer(new int[] {xx - 1, yy + 1, p[2] - 1});
					visited[xx - 1][yy + 1] = true;
				}
			} else if (dir == 4) {
				if (!isValid(xx, yy-1) && !walls[1][xx][yy - 1] &&
					!isValid(xx+1, yy-1) && !walls[0][xx + 1][yy - 1] &&
					!isValid(xx+1,yy-1) && !visited[xx + 1][yy - 1]) {
					q.offer(new int[] {xx + 1, yy - 1, p[2] - 1});
					visited[xx+1][yy-1] = true;
				}
				if (!isValid(xx+1, yy) && !walls[0][xx+1][yy] &&
					!isValid(xx+1,yy) && !visited[xx+1][yy]) {
					q.offer(new int[] {xx + 1, yy, p[2] - 1});
					visited[xx + 1][yy] = true;
				}
				if (!isValid(xx, yy) && !walls[1][xx][yy] &&
					!isValid(xx+1, yy+1) && !walls[0][xx+1][yy+1] &&
					!isValid(xx+1, yy+1) && !visited[xx+1][yy+1]) {
					q.offer(new int[] {xx + 1, yy + 1, p[2] - 1});
					visited[xx+1][yy+1] = true;
				}

			}
		}
	}

	static boolean nonWall(int dir, int x, int y) {

		switch (dir) {

			case 1: {
				// 오른쪽인 경우
				if (isValid(x, y) || walls[1][x][y]) return false;
				break;
			}
			case 2: {
				if (isValid(x,y-1) || walls[1][x][y-1]) return false;
				break;
			} case 3: {
				if (isValid(x,y) || walls[0][x][y]) return false;
				break;

			} case 4: {
				if (isValid(x+1, y) || walls[0][x+1][y]) return false;
				break;
			} default: break;
		}

		// 벽이 없는 경우임.
		return true;
	}

	// 2. 온도가 조절 -> 주변의 위치와의 온도차 비교
	static void control() {
		int[][] cc = new int[R + 1][C + 1];

		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {

				for (int d = 1; d <= 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];

					if (isValid(ni, nj)) continue;

					if (nonWall(d, i, j)) {
						int diff = 0;
						if (temp[i][j] >= temp[ni][nj]) {
							diff = (temp[i][j] - temp[ni][nj]) / 4;
							cc[i][j] -= diff;
							cc[ni][nj] += diff;
						}
					}
				}
			}
		}

		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				temp[i][j] += cc[i][j];
			}
		}

		for (int i = 1; i < R + 1; i++) {
			for (int j = 1; j < C + 1; j++) {
				if (temp[i][j] < 0) temp[i][j] = 0;
			}
		}

	}

	static boolean isValid(int x, int y) {
		if (x < 1 || x > R || y < 1 || y > C) return true;

		return false;
	}

	// 3. 바깥쪽 위치에 있는 온도 1씩 감소 시키기
	static void decrease() {

		for (int i = 1; i < C + 1; i++) {
			if(temp[1][i] - 1 >= 0) temp[1][i]--;
			if(temp[R][i] - 1 >= 0) temp[R][i]--;

			if (temp[1][i] < 0)
				temp[1][i] = 0;
			if (temp[R][i] < 0)
				temp[R][i] = 0;
		}

		for (int i = 2; i < R; i++) {
			if (temp[i][1] - 1 >= 0) temp[i][1]--;
			if (temp[i][C] - 1 >= 0) temp[i][C]--;

			if (temp[i][1] < 0)
				temp[i][1] = 0;
			if (temp[i][C] < 0)
				temp[i][C] = 0;
		}
	}

	// 5. 조사하려는 칸(5)에 대해서 모든 칸의 온도 K가 이상이 되었는지 검사한다.
	// 만약 false라면 다시 조사해야한다.
	static boolean test() {

		for (int i = 0; i < idx; i++) {
			if (temp[checks[i].x][checks[i].y] < K) return false;
		}

		return true;
	}
}
