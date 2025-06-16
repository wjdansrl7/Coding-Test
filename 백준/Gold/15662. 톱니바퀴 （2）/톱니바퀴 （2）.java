
import java.io.*;
import java.util.*;

public class Main {
	static int T, K;
	static int[][] tire;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int res = 0;

		T = Integer.parseInt(br.readLine()); // 톱니바퀴의 개수

		tire = new int[T + 1][8]; // 12시방향부터 저장된다.

		// 톱니바퀴 상태 저장
		for (int i = 1; i <= T; i++) {
			String str = br.readLine();

			for (int j = 0; j < 8; j++) {
				tire[i][j] = str.charAt(j) - '0';
			}
		}

		K = Integer.parseInt(br.readLine()); // 회전 횟수

		int num, dir; // 회전시킬 톱니바퀴 번호, 방향
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());

			num = Integer.parseInt(st.nextToken());
			dir = Integer.parseInt(st.nextToken());

			move(num, dir);

		}

		for (int j = 1; j <= T; j++) {
			if (tire[j][0] == 1) res++;
		}

		sb.append(res);
		System.out.println(res);


	}

	// N극: 0, S극: 1
	// 시계 방향:1 , 반시계방향: -1
	static void move(int num, int dir) {

		// 회전할 톱니바퀴 번호를 모아놓은 리스트
		List<int[]> changed = new ArrayList<>();
		changed.add(new int[]{num, dir});

		int tmp = dir;
		// 왼쪽 방향에 톱니바퀴가 돌 수 있는지?
		for (int i = num - 1; i >= 1; i--) {
			// i+1과 비교한다.

			// i번은 2번, i+1번은 6번
			if(tire[i][2] != tire[i+1][6]) {
				// 회전한다.
				changed.add(new int[]{i, -tmp});
				tmp = -tmp;
			} else break;

		}

		tmp = dir;
		for (int i = num + 1; i <= T; i++) {
			// i-1과 비교한다.

			// i-1번은 2번, i번은 6번 번호와 비교한다.
			if (tire[i - 1][2] != tire[i][6]) {
				changed.add(new int[]{i, -tmp});
				tmp = -tmp;
			} else break;
		}

		for (int[] c : changed) {
			rotation(c[0], c[1]);
		}
	}

	static void rotation(int num, int dir) {

		// 시계방향일 경우
		if (dir == 1) {
			// 이전항이 앞항으로 이동
			int tmp = tire[num][7];

			for (int i = 7; i >= 1; i--) {
				tire[num][i] = tire[num][i - 1];
			}

			tire[num][0] = tmp;
		} else {

			int tmp = tire[num][0];

			for (int i = 0; i < 7; i++) {
				tire[num][i] = tire[num][i + 1];
			}

			tire[num][7] = tmp;
		}
	}
}