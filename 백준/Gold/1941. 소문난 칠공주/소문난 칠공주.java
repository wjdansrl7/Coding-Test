
import java.util.*;
import java.io.*;
/**
 *packageName    : _250820
 * fileName       : BOJ_G3_1941_소문난칠공주
 * author         : moongi
 * date           : 8/21/25
 * description    :
 *
 * 조건
 * 1. 7명을 선택한다.
 * 2. 여기서 이다솜파의 사람이 4명이상이어야 한다.
 * 3. 공주들은 모두 연결되어야 한다.
 */
public class Main {
	static char[][] board = new char[5][5];
	static boolean[] visited = new boolean[25];
	static boolean[] isS = new boolean[25];
	static int ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ans = 0;

		for (int i = 0; i < 5; i++) {
			String str = br.readLine();

			for (int j = 0; j < 5; j++) {
				board[i][j] = str.charAt(j);
				isS[i * 5 + j] = (board[i][j] == 'S');
			}
		}
		
		solve(0, 0, 0);
		
		System.out.println(ans);
	}

	static void solve(int idx, int sCnt, int cnt) {

		// 남은 인원 + 현재 다솜이파의 수 < 4
		if (sCnt + (7 - cnt) < 4) return;

		// 도연이파가 3명을 넘어서는 경우
		int yCnt = cnt - sCnt;
		if (yCnt > 3) return;

		if (cnt == 7) {
			if (sCnt>=4 && connected()) ans++;
			
			return;
		}

		if (idx == 25) return;

		if (25 - idx < 7 - cnt) return;

		// 현재 칸을 선택하는 경우
		visited[idx] = true;
		solve(idx + 1, sCnt + (isS[idx] ? 1 : 0), cnt + 1);
		visited[idx] = false;

		// 선택하지 않는 경우
		solve(idx + 1, sCnt, cnt);
	}

	static boolean connected() {

		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};

		int start = -1;
		for (int i = 0; i < 25; i++) {
			if (visited[i]) {
				start = i;
				break;
			}
		}

		boolean[] pick = new boolean[25];
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.offer(start);
		pick[start] = true;
		int reached = 1;

		while (!q.isEmpty()) {

			int cur = q.poll();

			int x = cur / 5, y = cur % 5;

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
				int ni = nx * 5 + ny;
				if (pick[ni] || !visited[ni]) continue;
				pick[ni] = true;
				q.offer(ni);
				reached++;
			}
		}

		return reached == 7;
	}
}