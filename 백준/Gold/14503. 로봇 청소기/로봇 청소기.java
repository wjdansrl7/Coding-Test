import java.io.*;
import java.util.*;

/**
 *packageName    : _250731
 * fileName       : BOJ_G5_14503_로봇청소기
 * author         : moongi
 * date           : 7/31/25
 * description    :
 */
public class Main {

	static int[] dx = {-1, 0, 1, 0}; // 북, 동, 남, 서 0 1 2 3
	static int[] dy = {0, 1, 0, -1};

	static int[][] board;
	static int N, M;

	static class Node {
		int x, y, dir;

		public Node(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}

	static Node start;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		board = new int[N][M];

		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int dir = Integer.parseInt(st.nextToken());

		start = new Node(x, y, dir); // 시작 위치

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		System.out.println(solve());

	}

	static int solve() {

		int ans = 0;

		label: while (true) {
			int currX = start.x;
			int currY = start.y;
			int currDir = start.dir;

			// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
			if (board[currX][currY] == 0) {
				board[currX][currY] = 2;
				ans++;
			}

			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int nx = currX + dx[d];
				int ny = currY + dy[d];

				if (isValid(nx, ny)) {
					// 3. 현재 칸의 주변 칸 중 청소되지 않은 빈 칸이 있는 경우
					if (board[nx][ny] == 0) {

						cleaning();
						continue label;
					} else {
						// 이미 청소했거나, 청소할 수 없는 위치
						cnt++;
					}

				} else {
					cnt++;
				}
			}


			if (cnt == 4) {

				// 뒤로 후진
				currX += dx[(currDir + 2) % 4];
				currY += dy[(currDir + 2) % 4];

				// 후진한 위치가 이동할 수 없는 경우이거나, 벽으로 가로막힌 경우, 종료한다.
				if (!isValid(currX, currY) || board[currX][currY] == 1) {
					break;
				}

				// commit
				start.x = currX;
				start.y = currY;
			}
		}

		return ans;
	}

	private static void cleaning() {
		// 1. 반시계 방향으로 회전
		start.dir--;

		if (start.dir == -1) start.dir = 3;

		int nx = start.x + dx[start.dir];
		int ny = start.y + dy[start.dir];

		if (isValid(nx, ny) && board[nx][ny] == 0) {
			start.x = nx;
			start.y = ny;
		}
	}

	static boolean isValid(int x, int y) {

		if (x < 0 || x >= N || y < 0 || y >= M) return false;

		return true;
	}
}