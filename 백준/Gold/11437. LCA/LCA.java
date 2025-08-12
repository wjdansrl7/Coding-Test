import java.util.*;
import java.io.*;

/**
 *packageName    : _250812
 * fileName       : BOJ_G3_11437_LCA
 * author         : moongi
 * date           : 8/12/25
 * description    :
 */
public class Main {
	static int[] height, p;
	static List<Integer>[] graphs;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());

		height = new int[N + 1];
		p = new int[N + 1];
		graphs = new List[N + 1];

		Arrays.fill(p, -1);
		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		for (int i = 0; i < N - 1; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			graphs[a].add(b);
			graphs[b].add(a);
		}

		DFS(1,1,0);

		int M = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			sb.append(LCA(a, b)).append('\n');
		}
		System.out.println(sb);
	}

	static void DFS(int curr, int h, int parent) {
		height[curr] = h;
		p[curr] = parent;

		for(Integer next : graphs[curr]) {
			if (next != parent) {
				DFS(next, h + 1, curr);
			}
		}
	}

	static int LCA(int a, int b) {
		int ah = height[a];
		int bh = height[b];

		while (ah > bh) {
			a = p[a];
			ah = height[a];
		}

		while (ah < bh) {
			b = p[b];
			bh = height[b];
		}

		while (a != b) {
			a = p[a];
			b = p[b];
		}

		return a;
	}
}