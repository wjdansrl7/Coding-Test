
import java.util.*;
import java.io.*;
/**
 *packageName    : _250815
 * fileName       : BOJ_G3_1941_소문난칠공주
 * author         : moongi
 * date           : 8/15/25
 * description    :
 *
 * 처음 문제 풀이를 진행할 때, 고려하지 않은 부분은 단순하게 DFS를 돌리게된다면 분기되는 부분이 여러 개로
 * 나눠지지 않기 때문에 문제의 조건을 만족하지 않는다. -> 해밀턴 경로가 아니기 때문에
 *
 * 앞으로 문제를 풀 때, 이부분을 고려해서 문제를 꼼꼼이 읽고 파악하자.
 */
public class Main {

	static char[][] board = new char[5][5];
	static boolean[] pick = new boolean[25];
	static boolean[] isS = new boolean[25];
	static int ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// 학생들 입력
		ans = 0;

		for (int i = 0; i < 5; i++) {
			String str = br.readLine();
			for (int j = 0; j < 5; j++) {
				board[i][j] = str.charAt(j);
				isS[i * 5 + j] = (board[i][j] == 'S');
			}
		}

		// 소문난 칠공주를 결성할 수 있는 모든 경우의 수를 출력하라.

		// 조건
		// 1. 임도연파의 사람은 3명을 더 넘어서지 않는다.
		// 2. 사람을 모을 땐, 모든 사람들을 고려한다.
		// 3. 7명은 모두 가로나, 세로로 인접해있어야 한다.
		backTracking(0, 0, 0);
		System.out.println(ans);
		
	}

	/**
	 *
	 * @param idx: 현재 고려할 인덱스
	 * @param cnt: 현재까지 뽑은 공주들 수
	 * @param sCnt 이다솜파의 공주 수
	 */
	static void backTracking(int idx, int cnt, int sCnt) {

		// 다솜이가 4명을 못 넘는 경우
		if (sCnt + (7 - cnt) < 4) return;

		// 도연이가 3명을 넘어서는 경우
		int yCnt = cnt - sCnt;
		if (yCnt > 3) return;

		if (cnt == 7) {
			if (sCnt >= 4 && connected()) ans++;

			return;
		}

		if (idx == 25) return;

		// 남은 칸수가 모자르다면
		if (25 - idx < 7 - cnt) return;

		// 현재 idx칸을 선택
		pick[idx] = true;
		backTracking(idx+1, cnt+1, sCnt + (isS[idx] ? 1 : 0));
		pick[idx] = false;

		// 현재 idx칸을 선택하지 않는 경우
		backTracking(idx + 1, cnt, sCnt);


	}

	// 모든 점들이 연결되어 있는지 확인한다.
	static boolean connected() {

		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, 1, 0, -1};

		int start = -1;
		for (int i = 0; i < 25; i++) {
			if (pick[i]) {
				start = i;
				break;
			}
		}

		boolean[] visited = new boolean[25];
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.offer(start);
		visited[start] = true;
		int reached = 1;

		while (!q.isEmpty()) {

			int cur = q.poll();
			int x = cur / 5, y = cur % 5;
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				int ni = nx * 5 + ny;
				if (!pick[ni] || visited[ni]) continue;
				visited[ni] = true;
				q.offer(ni);
				reached++;
			}
		}

		return reached == 7;

	}
}