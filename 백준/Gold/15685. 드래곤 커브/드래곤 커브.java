import java.util.*;
import java.io.*;

/**
 *packageName    : _260302
 * fileName       : BOJ_G3_15685_드래곤커브
 * author         : moongi
 * date           : 3/2/26
 * description    :
 *
 * 0세대 드래곤 커브: (0,0)에 시작, -> 시작 방향은 오른쪽
 * 1세대 드래곤 커브: 0세대 드래곤 커브를 시계방향으로 90도 회전시킨 후, 끝 점과 붙인 것.
 * 2세대 드래곤 커브: 1세대 드래곤 커브를 똑같이 시계방향으로 90도 회전 시킨 후, 끝 점을 이어 붙인다.
 *
 * K세대 드래곤 커브: (K-1)세대 드래곤 커브를 끝 점을 기준으로 90도 시계 방향 회전 시킨 다음, 그것을 끝점에 붙인 것
 */
public class Main {
	private static final int RIGHT = 0;
	private static final int UP = 1;
	private static final int LEFT = 2;
	private static final int DOWN = 3;
	private static final int LENGTH = 101;
	private static boolean[][] map = new boolean[LENGTH][LENGTH];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int g = Integer.parseInt(st.nextToken());

			draw(x, y, getDirections(d, g));
		}

		sb.append(getNumberOfSquares());
		System.out.println(sb);

	}

	public static List<Integer> getDirections(int d, int g) {
		List<Integer> directions = new ArrayList<>(); // 방향을 담아줄 List 생성
		directions.add(d); // 초기 d 입력

		while (g-- > 0) {
			for (int i = directions.size()-1; i >= 0; i--) {
				int direction = (directions.get(i) + 1) % 4;
				directions.add(direction);
			}
		}
		return directions;
	}

	public static void draw(int x, int y, List<Integer> directions) {
		map[x][y] = true;

		for (int direction : directions) {
			switch (direction) {
				case RIGHT:
					map[++x][y] = true;
					break;
				case UP:
					map[x][--y] = true;
					break;
				case LEFT:
					map[--x][y] = true;
					break;
				case DOWN:
					map[x][++y] = true;
					break;
			}
		}
	}
	private static int getNumberOfSquares() {
		int count = 0;

		for (int x = 0; x < LENGTH - 1; x++) {
			for (int y = 0; y < LENGTH - 1; y++) {
				if (map[x][y] && map[x + 1][y] && map[x][y + 1] && map[x + 1][y + 1]) {
					count++;
				}
			}
		}
		return count;
	}
}