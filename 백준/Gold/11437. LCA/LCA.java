
import java.util.*;
import java.io.*;

/**
 *packageName    : _250803
 * fileName       : BOJ_G3_11437_LCA
 * author         : moongi
 * date           : 8/3/25
 * description    :
 */
public class Main {
	static int N, M;
	static List<Integer>[] graphs;
	static int[] depth;
	static int[] parents;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		graphs = new List[N + 1];

		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		depth = new int[N + 1];
		parents = new int[N + 1];

		int a, b;
		for (int i = 0; i < N - 1; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			graphs[a].add(b);
			graphs[b].add(a);
		}

		DFS(1, 1, 0);
		
		M = Integer.parseInt(br.readLine());

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			sb.append(LCA(a, b)).append('\n');

		}

		System.out.println(sb);

	}

	static void DFS(int curr, int height, int parent) {

		depth[curr] = height;
		parents[curr] = parent;

		for(Integer next : graphs[curr]) {

			if (next != parent) {
				DFS(next, height + 1, curr);
			}
		}

	}

	static int LCA(int a, int b) {

		int ah = depth[a];
		int bh = depth[b];

		while (ah > bh) {
			a = parents[a];
			ah--;
		}

		while (bh > ah) {
			b = parents[b];
			bh--;
		}

		while (a != b) {
			a = parents[a];
			b = parents[b];
		}

		return a;
	}

}