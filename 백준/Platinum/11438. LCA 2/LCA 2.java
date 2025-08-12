import java.util.*;
import java.io.*;

/**
 *packageName    : _250812
 * fileName       : BOJ_P5_11438_LCA2
 * author         : moongi
 * date           : 8/12/25
 * description    :
 * LCA + DP (memoization) -> to release time limit
 * Parent[][]의 값으 구하는 점화식
 * - Parent[m][n] = parent[Parent[m][n-1]][n-1]
 * -> m에서 위로 2^n칸 올라가는 것은 m에서 2^(n-1)만큼 올라간 뒤, 다시 2^(n-1) 올라간다라는 의미이다.
 * 2^(n-1) + 2 ^(n-1) = 2^n 이 되는 것과 같은 의미
 *
 * N(2<= N <= 100,000) 개 정점으로 이루어진 트리
 *
 *
 */
public class Main {
	static List<Integer>[] graphs;
	static int[] heights;
	static int[][] parents; // parents[v][k] = v의 2^k번째 조상
	static int N, M, LOG;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());

		// 트리의 높이 설정
		// LOG = ceil(log2(N))
		LOG = 1;
		while ((1 << LOG) <= N) LOG++;

		heights = new int[N + 1];
		parents = new int[N + 1][LOG];
		graphs = new List[N + 1];

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

		init(1);

		// parents 테이블 점화식 채우기
		// parents[i][j] = parents[parents[i][j-1]][j-1]
		for (int i = 1; i < LOG; i++) {
			for (int j = 1; j <= N; j++) {
				int mid = parents[j][i-1];
				parents[j][i] = (mid == 0 ? 0 : parents[mid][i - 1]);
			}
		}

		M = Integer.parseInt(br.readLine()); // query

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			sb.append(LCA(a, b)).append('\n');
		}

		System.out.println(sb);

	}

	// 트리(사이클 없음)이라는 전제가 있으므로 방문여부로 체크하지 않고,
	// 1. 부모로만 되돌아가는 간선
	// 2. 큐에 (노드, 부모) 쌍을 넣는 방법
	// 으로도 해결할 수 있다.

	// 루트에서 BFS/ DFS로 height, parents[v][0] 채우는 메서드
	static void init(int root) {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		parents[root][0] = 0;
		heights[root] = 1;
		q.offer(root);

		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int next : graphs[cur]) {
				if (parents[cur][0] == next) continue;
				parents[next][0] = cur;
				heights[next] = heights[cur] + 1;
				q.offer(next);
			}
		}

	}

	// 공통 조상 노드 찾는 메서드
	static int LCA(int a, int b) {

		// 높이가 더 놓은 것을 a에 맞춘다.
		if (heights[a] < heights[b]) {
			int tmp = b;
			b = a;
			a = tmp;
		}

		int diff = heights[a] - heights[b];

		for (int i = LOG - 1; i >= 0; i--) {
			if ((diff & (1 << i)) != 0) {
				a = parents[a][i];
			}
		}

		if (a == b) return a;

		for (int i = LOG - 1; i >= 0; i--) {
			if (parents[a][i] != parents[b][i]) {
				a = parents[a][i];
				b = parents[b][i];
			}
		}

		// 둘의 바로 위가 LCA
		return parents[a][0];

	}
}