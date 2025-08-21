
import java.util.*;
import java.io.*;
/**
 *packageName    : _250821
 * fileName       : BOJ_G4_4803_트리
 * author         : moongi
 * date           : 8/21/25
 * description    :
 *
 * 트리의 특징
 * 1. 사이클이 없는 상태이다.
 * 2. 정점이 n개, 간선이 n-1개
 * 3. 임의의 두 정점에 대해서 경로가 유일하다.
 *
 * DSU 패턴
 *
 */
public class Main {
	static int[] pa;
	static boolean[] cyc;
	public static void main(String[] args) throws Exception {
		// System.setIn(new FileInputStream("/Users/moongi/Desktop/SSAFY/Algorithm_Study/wjdansrl7/_250821/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int tc = 0;
		while (true) {
			st = new StringTokenizer(br.readLine());

			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());

			if (n == 0 && m == 0) break;
			tc++;

			// 부모 노드 초기화
			pa = new int[n + 1];
			cyc = new boolean[n + 1];

			for (int i = 0; i < n + 1; i++) {
				pa[i] = i;
			}

			// 간선간의 연결
			List<Integer> cycle = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int n1 = Integer.parseInt(st.nextToken());
				int n2 = Integer.parseInt(st.nextToken());

				// 정점간의 연결
				union(n1, n2);
			}

			Set<Integer> set = new HashSet<>();
			for (int i = 1; i < n + 1; i++) {
				set.add(find(i));
			}

			int trees = 0;
			for (Integer V : set) {
				if (!cyc[V]) trees++;
			}
			
			if (trees > 1) {
				sb.append("Case ").append(tc + ": ").append("A forest of ").append(trees).append(" trees.\n");
			} else if (trees == 1) {
				sb.append("Case ").append(tc + ": ").append("There is one tree.\n");
			} else {
				sb.append("Case ").append(tc + ": No trees.\n");
			}

		}

		System.out.println(sb);
	}

	static int find(int a) {
		if (pa[a] == a) return a;

		return pa[a] = find(pa[a]);
	}
	static boolean union(int a, int b) {

		a = find(a);
		b = find(b);

		if (a == b) {
			cyc[a] = true;
			return false;
		}

		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}

		pa[b] = a;
		cyc[a] = cyc[a] | cyc[b];

		return true;
	}
}