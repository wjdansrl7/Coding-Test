
import java.util.*;
import java.io.*;

/**
 *packageName    : _260315
 * fileName       : BOJ_S4_2578_빙고
 * author         : moongi
 * date           : 3/15/26
 * description    :
 */
public class Main {
	static int[][] board;
	static boolean[][] visited;

	static class Node {
		int x, y;

		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static Node[] nodes = new Node[26];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		board = new int[5][5];
		visited = new boolean[5][5];

		for (int i = 0; i < 26; i++) {
			nodes[i] = new Node(0, 0);
		}

		// input board
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				int v = Integer.parseInt(st.nextToken());
				board[i][j] = v;
				nodes[v].x = i;
				nodes[v].y = j;
			}
		}

		// call speaker
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				int N = Integer.parseInt(st.nextToken());

				// 사회자가 부른 숫자 방문 처리
				visited[nodes[N].x][nodes[N].y] = true;

				if (bingo(N) >= 3) {
					sb.append(i * 5 + j + 1);
					System.out.println(sb);
					return;
				}
			}
		}
	}

	static int bingo(int N) {
		int result = 0;

		for (int i = 0; i < 5; i++) {
			if (visited[i][0] && visited[i][1] && visited[i][2] && visited[i][3] && visited[i][4]) result++;
			if (visited[0][i] && visited[1][i] && visited[2][i] && visited[3][i] && visited[4][i]) result++;
		}

		if (visited[0][0] && visited[1][1] && visited[2][2] && visited[3][3] && visited[4][4]) result++;
		if (visited[0][4] && visited[1][3] && visited[2][2] && visited[3][1] && visited[4][0]) result++;

		return result;
	}
}