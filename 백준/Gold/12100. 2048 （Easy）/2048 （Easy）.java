import java.io.*;
import java.util.*;

/**
 *packageName    : _250516
 * fileName       : BOJ_G1_12100_2048_2
 * author         : moongi
 * date           : 5/16/25
 * description    :
 */
public class Main {
	static int[] dx = {0, -1, 0, 1, 0};
	static int[] dy = {0, 0, 1, 0, -1};

	static int[][] board;
	static int N, res = 0;
	static int[] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		visited = new int[5];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		combination(0, visited);

		System.out.println(res);

	}

	static int solve(int[][] arr) {
		int max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(arr[i][j] > max)
					max = arr[i][j];
			}
		}

		return max;
	}

	static void combination(int cnt, int[] visited) {
		if (cnt == 5) {
			int[][] tmp = new int[N][N];

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					tmp[i][j] = board[i][j];
				}
			}

			for (int i = 0; i < 5; i++) {
				move(tmp, visited[i]);
				sum(tmp, visited[i]);
				move(tmp, visited[i]);
			}

			int answer = solve(tmp);

			if(answer > res)
				res = answer;

			return;
		}

		for (int d = 1; d <= 4; d++) {
			visited[cnt] = d;
			combination(cnt+1, visited);
		}

	}


	static boolean isValid(int x, int y) {
		if (x < 0 || x >= N || y < 0 || y >= N)
			return false;

		return true;
	}

	static void sum(int[][] arr, int dir) {

		if (dir == 1) {
			// 위
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < N - 1; i++) {

					// 이전 행렬과의 합
					if (arr[i][j] == arr[i + 1][j]) {
						arr[i][j] += arr[i + 1][j];
						arr[i + 1][j] = 0;
						i++;
					}

				}
			}
		} else if (dir == 2) {
			// -> // 2
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j >= 1; j--) {

					// 이전 행렬과의 합
					if (arr[i][j] == arr[i][j - 1]) {
						arr[i][j] += arr[i][j - 1];
						arr[i][j - 1] = 0;
						j--;
					}

				}
			}
		} else if (dir == 3) {
			// 아래
			for (int j = 0; j < N; j++) {
				for (int i = N - 1; i >= 1; i--) {

					// 이전 행렬과의 합
					if (arr[i][j] == arr[i - 1][j]) {
						arr[i][j] += arr[i - 1][j];
						arr[i - 1][j] = 0;
						i--;
					}

				}
			}
		} else {
			// <- // 4
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N - 1; j++) {

					// 이전 행렬과의 합
					if (arr[i][j] == arr[i][j + 1]) {
						arr[i][j] += arr[i][j + 1];
						arr[i][j + 1] = 0;
						j++;
					}

				}
			}
		}

	}

	/**
	 * 이동
	 * @param dir : 해당하는 방향
	 */
	static void move(int[][] arr, int dir) {

		if (dir == 1) {
			// 위
			for (int j = 0; j < N; j++) {
				for (int i = 0; i < N; i++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (!isValid(nx, ny))
						continue;

					if (arr[nx][ny] != 0) continue;

					while (true) {
						nx += dx[dir];
						ny += dy[dir];

						if (!isValid(nx, ny)) break;
						if (arr[nx][ny] != 0) break;
					}

					nx -= dx[dir];
					ny -= dy[dir];

					arr[nx][ny] = arr[i][j];
					arr[i][j] = 0;

				}
			}
		} else if (dir == 2) {

			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j >= 0; j--) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (!isValid(nx, ny))
						continue;

					if (arr[nx][ny] != 0) continue;

					while (true) {
						nx += dx[dir];
						ny += dy[dir];

						if (!isValid(nx, ny)) break;
						if (arr[nx][ny] != 0) break;
					}

					nx -= dx[dir];
					ny -= dy[dir];

					arr[nx][ny] = arr[i][j];
					arr[i][j] = 0;

				}
			}

		} else if (dir == 3) {
			for (int j = 0; j < N; j++) {
				for (int i = N - 1; i >= 0; i--) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (!isValid(nx, ny))
						continue;

					if (arr[nx][ny] != 0) continue;

					while (true) {
						nx += dx[dir];
						ny += dy[dir];

						if (!isValid(nx, ny)) break;
						if (arr[nx][ny] != 0) break;
					}

					nx -= dx[dir];
					ny -= dy[dir];

					arr[nx][ny] = arr[i][j];
					arr[i][j] = 0;

				}
			}
		} else {

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (!isValid(nx, ny))
						continue;

					if (arr[nx][ny] != 0) continue;

					while (true) {
						nx += dx[dir];
						ny += dy[dir];

						if (!isValid(nx, ny)) break;
						if (arr[nx][ny] != 0) break;
					}

					nx -= dx[dir];
					ny -= dy[dir];

					arr[nx][ny] = arr[i][j];
					arr[i][j] = 0;

				}
			}
		}
	}
}