
import java.io.*;
import java.util.*;

public class Main {
	static int N, M, res, dist;
	static int[][] board;

	static class Room {
		int x, y, num;

		public Room(int x, int y, int num) {
			this.x = x;
			this.y = y;
			this.num = num;
		}
	}

	static Room[] rooms;

	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		res = 0;
		dist = 0;

		board = new int[N][M];
		rooms = new Room[N*M];
		int idx = 0;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());

				if (board[i][j] != 0)
					rooms[idx++] = new Room(i, j, board[i][j]);
			}
		}

		for (int i = 0; i < idx; i++) {
			bfs(rooms[i]);
		}

		System.out.println(res);
	}
	static void bfs(Room start) {
		boolean[][] visited = new boolean[N][M];
		ArrayDeque<int[]> q = new ArrayDeque<>();
		
		visited[start.x][start.y] = true;
		q.offer(new int[] {start.x, start.y, 0});

		while (!q.isEmpty()) {
			int[] p = q.poll();
			int cnt = 0;

			for (int d = 0; d < 4; d++) {
				int nx = p[0] + dx[d];
				int ny = p[1] + dy[d];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || board[nx][ny] == 0) {
					cnt++;
					continue;
				}

				visited[nx][ny] = true;
				q.offer(new int[] {nx, ny, p[2] + 1});
			}

			if (cnt == 4) {
				if (p[2] > dist) {
					dist = p[2];
					res = start.num + board[p[0]][p[1]];
				} else if (p[2] == dist)
					res = start.num + board[p[0]][p[1]] > res ? start.num + board[p[0]][p[1]] : res;
			}
		}
	}
}