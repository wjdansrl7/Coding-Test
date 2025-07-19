
import java.io.*;
import java.util.*;

/**
 *packageName    : _250719
 * fileName       : BOJ_G5_20055_컨테이어벨트위의로봇
 * author         : moongi
 * date           : 7/19/25
 * description    :
 */
public class Main {
	static int N, K;
	static int[] containers;
	static boolean[] visited;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		containers = new int[N * 2];
		visited = new boolean[N * 2];

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N * 2; i++) {
			containers[i] = Integer.parseInt(st.nextToken());
		}

		int turn = 1;

		while (true) {

			int count = 0;
			// 1. 모든 로봇과 벨트가 한 칸씩 회전
			rotation();

			if (visited[N-1]) visited[N-1] = false;

			// 2. 로봇들의 이동
			canMove();

			if (visited[N-1]) visited[N-1] = false;

			// 3. 로봇 올리기
			if (!visited[0] && containers[0] >= 1) {
				containers[0]--;
				visited[0] = true;
			}

			// 4. 내구도 개수가 0인 칸들에 대한 valid

			for (int i = 0; i < 2 * N; i++) {
				if (containers[i] == 0) count++;
			}

			if (count >= K) {
				break;
			}
			
			turn++;
		}

		sb.append(turn);
		System.out.println(sb);
	}

	static void rotation() {

		int tmp = containers[2 * N - 1];
		boolean tmp2 = visited[2 * N - 1];

		for (int i = 2 * N - 1; i >= 1; i--) {
			containers[i] = containers[i - 1];
			visited[i] = visited[i - 1];
		}
		containers[0] = tmp;
		visited[0] = tmp2;
		
	}

	static void canMove() {

		// 로봇이 이동하는 방향에 다른 로봇이 없다면 이동 with 내구도 >= 1
		for (int i = N - 2; i >= 0; i--) {

			if (visited[i] && !visited[i + 1] && containers[i + 1] >= 1) {
				visited[i + 1] = true;
				visited[i] = false;
				containers[i + 1]--;
			}
		}
	}
}