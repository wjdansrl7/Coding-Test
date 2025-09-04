import java.util.*;
import java.io.*;
/**
 *packageName    : _250904
 * fileName       : BOJ_G5_7511_소셜네트워킹어플리케이션
 * author         : moongi
 * date           : 9/4/25
 * description    :
 *
 * // 두 사람 사이의 경로가 존재하는지 안 하는지를 미리 구해본다.
 */
public class Main {
	static int N;
	static int[] pa;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			N = Integer.parseInt(br.readLine()); // 유저의 수 <= 10^6
			int K = Integer.parseInt(br.readLine()); // 친구 관계의 수 <= 10^5

			pa = new int[N];
			for (int i = 0; i < N; i++) {
				pa[i] = i;
			}

			sb.append("Scenario ").append(tc + 1).append(":\n");

			// 친구 관계의 수 a, b
			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());

				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				union(a, b);

			}

			int M = Integer.parseInt(br.readLine()); // 구해야할 쌍의 수

			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				a = find(a);
				b = find(b);

				if (a == b) sb.append(1).append('\n');
				else sb.append(0).append('\n');
			}

			sb.append('\n');
		}

		System.out.println(sb);

	}

	static boolean union(int a, int b) {
		a = find(a);
		b = find(b);

		if (a == b) {
			return false;
		} else if (a > b) {
			pa[a] = b;
		} else {
			pa[b] = a;
		}

		return true;
	}

	static int find(int a) {
		if (pa[a] == a) return a;

		return pa[a] = find(pa[a]);
	}
}