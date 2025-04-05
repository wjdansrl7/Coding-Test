
import java.util.*;
import java.io.*;

public class Main {
	static boolean[][] visited;

	static Bingo[] board;

	static class Bingo {
		int x, y;

		public Bingo(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		visited = new boolean[5][5];
		board = new Bingo[26];

		int target;
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				target = Integer.parseInt(st.nextToken());
				board[target] = new Bingo(i, j);
			}
		}

		int N, x, y;
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				N = Integer.parseInt(st.nextToken());

				visited[board[N].x][board[N].y] = true;
				if (col() + row() + side() >= 3) {
					System.out.println(i * 5 + j + 1);
					return;
				}
			}
		}
	}

	static int col() {
		int cnt = 0;

		for (int i = 0; i < 5; i++) {
			boolean flag =false;
			for (int j = 0; j < 5; j++) {
				if (!visited[i][j]) {
					flag = true;
					break;
				}
			}
			if (!flag) cnt++;
		}

		return cnt;
	}

	static int row() {
		int cnt = 0;

		for (int i = 0; i < 5; i++) {
			boolean flag =false;
			for (int j = 0; j < 5; j++) {
				if (!visited[j][i]) {
					flag = true;
					break;
				}
			}
			if (!flag) cnt++;
		}

		return cnt;
	}

	static int side() {
		int cnt = 0;

		boolean flag = false;
		for (int i = 0; i < 5; i++) {
			if (!visited[i][i]) {
				flag = true;
				break;
			}
		}
		if (!flag)
			cnt++;

		flag = false;
		for (int i = 0; i < 5; i++) {
			if (!visited[i][4 - i]) {
				flag = true;
				break;
			}
		}

		if (!flag)
			cnt++;

		return cnt;
	}
}