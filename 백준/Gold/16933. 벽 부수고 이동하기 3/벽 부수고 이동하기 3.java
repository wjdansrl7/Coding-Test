import java.io.*;
import java.util.*;

/**
 *packageName    : _250802
 * fileName       : BOJ_G1_16933_벽부수고이동하기3
 * author         : moongi
 * date           : 8/2/25
 * description    :
 *
 * 조건:
 * 1. 최대 벽은 K개까지 부술 수 있다
 * 2. 벽은 낮에만 부실 수 있다.
 * 3. 제자리에 머무르는 경우가 있고, 해당 경우에도 똑같이 밤, 낮이 바뀌고, 이동 경로로 간주하고, 카운팅한다.
 * 4. 처음 시작은 낮부터 시작한다.
 *
 */
public class Main {
	static int N, M, K, ans;
	static int[][] board;
	static int[][][][] dist;

	static class Node {
		int x, y, w,day;

		public Node(int x, int y, int w, int day) {
			this.x = x;
			this.y = y;
			this.w = w;
			this.day = day;
		}
	}

	static final int INF = Integer.MAX_VALUE;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken()); // 부술 수 있는 벽의 개수 <= 10

		board = new int[N + 1][M + 1];


		for (int i = 1; i < N + 1; i++) {
			String str = br.readLine();
			for (int j = 1; j < M + 1; j++) {
				board[i][j] = str.charAt(j - 1) - '0';
			}
		}

		dist = new int[K + 1][N + 1][M + 1][2];
		for (int i = 0; i < K + 1; i++) {
			for (int j = 0; j < N + 1; j++) {
				for (int k = 0; k < M + 1; k++) {
					dist[i][j][k][0] = dist[i][j][k][1] = INF;
				}
			}
		}

		BFS();

		int ans = INF;
		for (int w = 0; w <= K; w++) {
			ans = Math.min(ans, dist[w][N][M][0]);
			ans = Math.min(ans, dist[w][N][M][1]);
		}

		System.out.println(ans == INF ? -1 : ans);
	}


	// 제자리에서도 경로가 추가된다.
	static void BFS() {
		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};

		ArrayDeque<Node> q = new ArrayDeque<>();

		// w, x, y, day
		dist[0][1][1][0] = 1;
		q.offer(new Node(1, 1, 0, 0));

		while (!q.isEmpty()) {

			Node cur = q.poll();
			int x = cur.x, y = cur.y, w = cur.w, day = cur.day;
			int curDist = dist[w][x][y][day];
			int nextDay = 1 - day;

			// 1. 제자리 대기 (하루 경과 -> 낮/밤 토글)
			if (dist[w][x][y][nextDay] > curDist + 1) {
				dist[w][x][y][nextDay] = curDist + 1;
				q.offer(new Node(x, y, w, nextDay));
			}

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];

				if (!isValid(nx, ny)) continue;

				if (board[nx][ny] == 0) {
					if (dist[w][nx][ny][nextDay] > curDist + 1) {
						dist[w][nx][ny][nextDay] = curDist + 1;
						q.offer(new Node(nx, ny, w, nextDay));
					}
				} else if (board[nx][ny] == 1 && day == 0 && w < K) {
					if (dist[w + 1][nx][ny][nextDay] > curDist + 1) {
						dist[w + 1][nx][ny][nextDay] = curDist + 1;
						q.offer(new Node(nx, ny, w + 1, nextDay));
					}
				}
			}
		}
	}

	static boolean isValid(int x, int y) {
		if (x < 1 || x > N || y < 1 || y > M) return false;

		return true;
	}
}