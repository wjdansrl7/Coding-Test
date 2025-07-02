
import java.util.*;
import java.io.*;
/**
 *packageName    : _250702
 * fileName       : BOJ_G4_3190_뱀
 * author         : moongi
 * date           : 7/2/25
 * description    :
 * 뱀은 매초마다 한 칸씩 이동한다.
 * 뱀은 초기에 오른쪽을 향한다. -> dir: 1
 * 벽에 부딪히거나, 자기 자신의 몸과 부딪힐 시, 게임은 종료된다.
 * 사과 있는 곳에 위치하면 해당 위치를 뱀의 영역으로 변경한다.
 * 사과가 없다면 꼬리 부분의 위치를 빈 공간을 변경한다.
 *
 */
public class Main {

	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};

	static List<int[]> snakes;
	static int N;
	static Map<Integer, Character> map;
	static int[][] board;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		int K = Integer.parseInt(br.readLine());

		board = new int[N + 1][N + 1];
		snakes = new ArrayList<>();
		map = new HashMap<>();

		int x, y;
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());

			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			board[x][y] = 1; // 사과
		}

		int L = Integer.parseInt(br.readLine());

		int X;
		char C;
		for (int i = 0; i < L; i++) {
			st = new StringTokenizer(br.readLine());
			X = Integer.parseInt(st.nextToken());
			C = st.nextToken().charAt(0);

			map.put(X, C);
		}

		sb.append(play());
		System.out.println(sb);

	}

	static int play() {
		int cx = 1, cy = 1;
		int time = 0;
		snakes.add(new int[] {1, 1});
		int dir = 1;

		while (true) {

			time++;

			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			// 벽이나 자기자신에 부딪힌 경우
			if(!isValid(nx, ny)) break;

			if (board[nx][ny] == 1) {
				board[nx][ny] = 0;
				snakes.add(new int[] {nx, ny});

			} else {
				snakes.add(new int[]{nx, ny});
				snakes.remove(0);
			}

			// X초가 끝난 뒤, 방향 전환 확인
			if (map.containsKey(time)) {

				char d = map.get(time);

				if (d == 'L') {
					dir--;
					if (dir < 0) dir = 3;
				} else {
					dir++;
					if (dir > 3) dir = 0;
				}
			}

			cx = nx;
			cy = ny;
			
		}

		return time;

	}

	static boolean isValid(int x, int y) {
		if (x > N || x < 1 || y > N || y < 1) return false;

		for (int[] snake : snakes) {
			if(snake[0] == x && snake[1] == y) return false;
		}

		return true;
	}
}
