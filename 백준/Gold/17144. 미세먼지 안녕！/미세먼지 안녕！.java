
import java.util.*;
import java.io.*;

/**
 *packageName    : _250703
 * fileName       : BOJ_G4_17144_미세먼지안녕
 * author         : moongi
 * date           : 7/3/25
 * description    :
 */
public class Main {
	static int R, C, T;
	static int[][] board;
	static int[] conditioner;

	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());

		board = new int[R][C];
		conditioner = new int[2];

		int idx = 0;
		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < C; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());

				// 공기 청정기의 위치 저장
				if (board[i][j] == -1) {
					conditioner[idx++] = i;
				}
			}
		}

		int time = 0;
		while(time < T) {

			moveDust();
			moveAir(conditioner);
			
			// 1초 경과
			time++;
		}

		int ans = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				ans += board[i][j];

			}
		}

		sb.append(ans + 2);
		System.out.println(sb);
		
	}

	static void moveDust() {
		int[][] tmp = new int[R][C];

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {

				int sum = 0;
				int part = board[i][j] / 5;

				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];

					if (!isValid(nx, ny)) continue;

					tmp[nx][ny] += part;
					sum += part;

				}

				tmp[i][j] += board[i][j] - sum;

			}
		}

		// 먼지 확산 이후
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				board[i][j] = tmp[i][j];
			}
		}

		// 공기 청정기 위치
		board[conditioner[0]][0] = -1;
		board[conditioner[1]][0] = -1;

	}

	static boolean isValid(int x, int y) {
		if (x >= R || x < 0  || y >= C || y < 0 || board[x][y] == -1) return false;

		return true;
	}

	static void moveAir(int[] conditioner) {
		// 모두 한 칸씩 이동하며, 공기 청정기 위치에 도착 시, 해당 먼지는 제거

		// 위쪽 공기 청정기: 반시계 방향

		for (int i = conditioner[0] - 1; i >= 1; i--) {
			board[i][0] = board[i - 1][0];
		}

		for (int i = 0; i < C - 1; i++) {
			board[0][i] = board[0][i + 1];
		}

		for (int i = 0; i < conditioner[0]; i++) {
			board[i][C - 1] = board[i + 1][C - 1];
		}

		for (int i = C - 1; i > 1; i--) {
			board[conditioner[0]][i] = board[conditioner[0]][i - 1];
		}

		board[conditioner[0]][1] = 0;

		// 아래쪽 공기 청정기: 시계 방향

		for (int i = conditioner[1] + 1; i < R - 1; i++) {
			board[i][0] = board[i + 1][0];
		}

		for (int i = 0; i < C - 1; i++) {
			board[R - 1][i] = board[R - 1][i + 1];
		}

		for (int i = R-1; i > conditioner[1]; i--) {
			board[i][C - 1] = board[i - 1][C - 1];
		}

		for (int i = C - 1; i > 1; i--) {
			board[conditioner[1]][i] = board[conditioner[1]][i - 1];
		}

		board[conditioner[1]][1] = 0;
	}
}