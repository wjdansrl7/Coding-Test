
import java.io.*;
import java.util.*;


public class Main {

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static Point[] points = new Point[26];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		boolean[][] visited = new boolean[5][5];

		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				int idx = Integer.parseInt(st.nextToken());
				points[idx] = new Point(i, j);
			}
		}


		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());

			for (int j = 0; j < 5; j++) {
				int call = Integer.parseInt(st.nextToken());
				Point curr = points[call];

				if (game(curr, visited)) {
					System.out.println(i * 5 + j + 1);
					return;
				}
			}
		}
	}

	static boolean game(Point p, boolean[][] visited) {
		visited[p.x][p.y] = true;
		int bingo = 0;
		int count;

		// col
		for (int i = 0; i < 5; i++) {
			count = 0;
			for (int j = 0; j < 5; j++) {
				if (visited[i][j]) count++;
				else break;
			}

			if (count == 5) bingo++;
			if (bingo == 3) return true;
		}

		// row
		for (int i = 0; i < 5; i++) {
			count = 0;
			for (int j = 0; j < 5; j++) {
				if (visited[j][i]) count++;
				else break;
			}

			if (count == 5) bingo++;
			if (bingo == 3) return true;
		}

		// side
		count = 0;
		for (int i = 0; i < 5; i++) {
			if(visited[i][i]) count++;
			else break;
		}

		if (count == 5) bingo++;
		if (bingo == 3) return true;

		count = 0;
		for (int i = 0; i < 5; i++) {
			if(visited[i][4-i]) count++;
			else break;
		}

		if (count == 5) bingo++;
		if (bingo == 3) return true;

		return false;
	}
}
