import java.util.*;
import java.io.*;

/**
 *packageName    : _251004
 * fileName       : BOJ_G5_24391_귀찮은해강이
 * author         : moongi
 * date           : 10/4/25
 * description    :
 */
public class Main {
	static int N, M;
	static int[] pa;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken()); // 강의의 개수
		M = Integer.parseInt(st.nextToken()); // 건물의 쌍의 개수

		pa = new int[N + 1];

		for (int i = 0; i < N + 1; i++) {
			pa[i] = i;
		}
		
		// 건물간의 연결
		int a, b;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			union(a, b);

		}

		int ans = 0; // 이동 횟수
		int cur, next; // 현재 위치
		st = new StringTokenizer(br.readLine()); // 강의 시간표

		cur = Integer.parseInt(st.nextToken());
		cur = find(cur);

		for (int i = 1; i < N; i++) {
			next = Integer.parseInt(st.nextToken());

			next = find(next);

			if (cur != next) {
				ans++;
				cur = next;
			}

		}

		System.out.println(ans);

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