
import java.util.*;
import java.io.*;

/**
 *packageName    : _250804
 * fileName       : BOJ_P5_11438_LCA2
 * author         : moongi
 * date           : 8/4/25
 * description    :
 */
public class Main {
	static final int MAX = 100_000;
	static final int LOG = 17;
	static int N, M;
	static List<Integer>[] tree = new ArrayList[MAX + 1];
	static int[][] parent = new int[MAX + 1][LOG + 1];
	static int[] depth = new int[MAX + 1];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		for (int i = 1; i <= N; i++) {
			tree[i] = new ArrayList<>();
		}

		for (int i = 0; i < N - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			tree[u].add(v);
			tree[v].add(u);
		}
		// 1번 노드를 루트로 깊이(depth)와 1차 부모(parent[][0]) 구하기
		bfs(1);

		fillParents();

		StringBuilder sb = new StringBuilder();
		M = Integer.parseInt(br.readLine());

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			sb.append(lca(a, b)).append('\n');
		}

		System.out.println(sb);

	}

	// BFS로 깊이(depth)와 1차 부모(parent[][0])를 채운다.
	static void bfs(int root) {
		boolean[] visited = new boolean[N + 1];
		Queue<Integer> q = new LinkedList<>();
		visited[root] = true;
		depth[root] = 0;
		q.offer(root);

		while (!q.isEmpty()) {
			int u = q.poll();
			for(int v : tree[u]) {
				if (!visited[v]) {
					visited[v] = true;
					depth[v] = depth[u] + 1;
					parent[v][0] = u;
					q.offer(v);
				}
			}
		}
	}

	// DP: parent[i][k] = parent[parent[i][k-1]][k-1] 로 채우기
	// 2^1, 2^2, 2^3 ... 부모 노드로 채우기 때문에 2^N 부모 노드 = 2^(N/2) * 2^(N/2)로 구한다.
	static void fillParents() {
		for (int k = 1; k <= LOG; k++) {
			for (int v = 1; v <= N; v++) {
				int mid = parent[v][k - 1];
				parent[v][k] = (mid == 0 ? 0 : parent[mid][k - 1]);
			}
		}
	}

	// 두 노드의 LCA 구하기
	static int lca(int u, int v) {
		// 1. 깊이 맞추기
		if (depth[u] < depth[v]) {
			int tmp = u; u = v; v = tmp;
		}

		int diff = depth[u] - depth[v];
		for (int k = 0; k <= LOG; k++) {
			if ((diff & (1 << k)) != 0) {
				u = parent[u][k];
			}
		}

		// 2. 같아졌으면 반환
		if (u == v) return u;

		for (int k = LOG; k >= 0; k--) {
			if (parent[u][k] != 0 && parent[u][k] != parent[v][k]) {
				u = parent[u][k];
				v = parent[v][k];
			}
		}

		// 4) 최종 부모(1차 부모)가 LCA
		return parent[u][0];

	}
}