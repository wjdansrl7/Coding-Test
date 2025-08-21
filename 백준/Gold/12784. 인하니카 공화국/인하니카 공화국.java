import java.util.*;
import java.io.*;

/**
 *packageName    : _250821
 * fileName       : BOJ_G3_12784_인하니카공화국
 * author         : moongi
 * date           : 8/21/25
 * description    :
 *
 * problem solving
 * 1. leaf node 들의 연결을 끊어야함.
 * 2. Math.min(curr's weight, left's weight + right's weight)
 * 3. not binary tree
 *
 */
public class Main {
	static List<Node>[] nodes;

	static class Node {
		int to, weight;

		public Node(int to, int weight) {
			this.to = to;
			this.weight = weight;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();

		while (T-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken()); // 섬의 수
			int M = Integer.parseInt(st.nextToken()); // 다리 수

			nodes = new List[N + 1];
			for (int i = 0; i < N + 1; i++) {
				nodes[i] = new ArrayList<>();
			}

			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()); // 섬의 번호
				int b = Integer.parseInt(st.nextToken()); // 섬의 번호
				int D = Integer.parseInt(st.nextToken()); // 다이너마이트의 수

				// 섬끼리 연결
				nodes[a].add(new Node(b, D));
				nodes[b].add(new Node(a, D));
			}

			if (N == 1) {
				sb.append(0).append('\n');
				continue;
			}

			sb.append(dfs(1, -1, Integer.MAX_VALUE)).append('\n');
		}

		System.out.println(sb);

	}

	/**
	 * 
	 * @param u : 현재 노드의 번호
	 * @param pa : 노드의 부모 번호
	 * @param uW : 현재 노드의 가중치
	 * @return 현재 노드의 간선과 자식들의 간선들의 합을 비교하여 최솟값을 반환한다.
	 */
	static int dfs(int u, int pa, int uW) {
		int ret = 0;

		for (Node next : nodes[u]) {
			if (next.to != pa) {
				// 부모 노드가 아니면서
				ret += dfs(next.to, u, next.weight);
			}
		}

		if (ret == 0) {
			// leaf node
			return uW;
		}

		return Math.min(uW, ret);
	}
}