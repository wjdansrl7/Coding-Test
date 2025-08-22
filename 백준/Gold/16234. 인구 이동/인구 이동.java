import java.util.*;
import java.io.*;

/**
 *packageName    : _250821
 * fileName       : BOJ_G4_16234_인구이동
 * author         : moongi
 * date           : 8/21/25
 * description    :
 */
public class Main {
	static int[][] board, changed, cnt;
	static boolean[][] visited;
	static int N, L, R;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		board = new int[N + 1][N + 1]; // 각각의 칸의 인구
		changed = new int[N + 1][N + 1]; // 같은 국경안의 지역들을 idx로 저장
		cnt = new int[N * N + 1][2]; // [0]: 연합의 인구수 총합 / [1]: 연합의 총 개수

		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());

			for (int j = 1; j < N + 1; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int ans = 0;
		while (true) {
			visited = new boolean[N + 1][N + 1];
			int idx = 1;

			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					if (!visited[i][j]) {
						BFS(i, j, idx++);
					}
				}
			}

			if (idx > N * N) break;

			// 인구 이동 반영
			movePeople();

			ans++;

			init();

		}
		
		System.out.println(ans);
	}

	static void init() {
		cnt = new int[N * N + 1][2]; // 인구 이동 초기화
		changed = new int[N + 1][N + 1]; // 연합 idx 초기화
	}

	static void movePeople() {
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				// 변화된 인구수
				int sum = cnt[changed[i][j]][0] / cnt[changed[i][j]][1];
				board[i][j] = sum;
			}
		}
	}

	static void BFS(int x, int y, int idx) {
		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};

		ArrayDeque<int[]> q = new ArrayDeque<>(); // 이동할 방향

		q.offer(new int[] {x, y});
		changed[x][y] = idx;
		visited[x][y] = true;
		cnt[idx][0] += board[x][y];
		cnt[idx][1]++;

		while (!q.isEmpty()) {

			int[] cur = q.poll();

			for (int d = 0; d < 4; d++) {
				int nx = cur[0] + dx[d];
				int ny = cur[1] + dy[d];

				if (nx < 1 || nx > N || ny < 1 || ny > N || visited[nx][ny]) continue;

				int diff = Math.abs(board[nx][ny] - board[cur[0]][cur[1]]);

				if (diff < L || diff > R) continue;

				q.offer(new int[] {nx, ny});
				visited[nx][ny] = true;
				changed[nx][ny] = idx;
				cnt[idx][0] += board[nx][ny];
				cnt[idx][1]++;
			}
		}
	}
}