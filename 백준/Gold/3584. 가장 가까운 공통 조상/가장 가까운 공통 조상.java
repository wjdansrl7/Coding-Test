
import java.util.*;
import java.io.*;

/**
 *packageName    : _250515
 * fileName       : BOJ_G4_3584_가장가까운공통조상
 * author         : moongi
 * date           : 5/15/25
 * description    :
 *
 * A가 B의 부모 p[B] = A;
 *
 * 두 노드의 가장 가까운 조상의 번호를 입력하라.
 */
public class Main {
	static int N;
	static int[] p;

	static class Node {
		int num;
		List<Integer> nodeList;

		public Node(int num, List<Integer> nodeList) {
			this.num = num;
			this.nodeList = nodeList;
		}
	}

	static void init() {

		nodes = new Node[N + 1];

		for (int i = 0; i < N + 1; i++) {
			nodes[i] = new Node(i, new ArrayList<>());
		}

		p = new int[N + 1];

		for (int i = 0; i < N + 1; i++) {
			p[i] = i;
		}

		height = new int[N + 1];

	}

	static Node[] nodes;
	static int[] height;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		while (T-- > 0) {
			N = Integer.parseInt(br.readLine());

			init();

			int a, b;
			for (int i = 0; i < N - 1; i++) {
				st = new StringTokenizer(br.readLine());

				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());

				p[b] = a;
				nodes[a].nodeList.add(b);

 			}

			int root = 0;

			for (int i = 1; i < N + 1; i++) {
				if (p[i] == i) {
					root = i;
					break;
				}
			}

			// 노드들의 높이 구하기
			DFS(root, 0);
			
			st = new StringTokenizer(br.readLine());

			// 구하고자하는 노드의 번호
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			int res = balanceH(a, b);

			sb.append(res).append('\n');

		}

		System.out.println(sb);
	}

	static void DFS(int start, int h) {

		boolean[] visited = new boolean[N + 1];
		ArrayDeque<int[]> q = new ArrayDeque<>();

		q.offer(new int[]{start, 0});
		visited[start] = true;

		while (!q.isEmpty()) {

			int[] curr = q.poll();

			for(Integer next : nodes[curr[0]].nodeList) {
				if (visited[next]) continue;
				visited[next] = true;

				height[next] = curr[1] + 1;
				q.offer(new int[] {next, curr[1] + 1});
			}
		}
	}

	static int balanceH(int a, int b) {
		int aH = height[a];
		int bH = height[b];

		if (aH > bH) {
			while (aH != bH) {
				a = p[a];
				aH--;
			}
		} else {
			while (aH != bH) {
				b = p[b];
				bH--;
			}
		}
		// a와 b가 서로 높이가 동일할 경우
		while(a != b) {
			a = p[a];
			b = p[b];
		}

		return a;
	}
}
