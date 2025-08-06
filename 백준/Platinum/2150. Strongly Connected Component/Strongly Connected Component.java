
import java.util.*;
import java.io.*;
/**
 *packageName    : _250805
 * fileName       : BOJ_P5_2150_StronglyConnectedComponent
 * author         : moongi
 * date           : 8/5/25
 * description    :
 * SCC에서 필요한 것
 * 1. Directed Graph, Reverse Directed Graph, Stack
 */
public class Main {
	static int V, E;
	static List<Integer>[] diGraphs, rdiGraphs, ans;
	static boolean[] visited;
	static Stack<Integer> stk;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		diGraphs = new List[V + 1];
		rdiGraphs = new List[V + 1];
		ans = new List[V + 1];

		stk = new Stack<>();

		for (int i = 0; i < V + 1; i++) {
			diGraphs[i] = new ArrayList<>();
			rdiGraphs[i] = new ArrayList<>();
			ans[i] = new ArrayList<>();
		}

		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			diGraphs[a].add(b);
			rdiGraphs[b].add(a);

		}

		visited = new boolean[V + 1];

		// 방향 그래프에 대하여 dfs를 수행하고,
		// 탐색이 종료되는 점부터 스택에 push 함.

		for (int i = 1; i < V + 1; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}

		Arrays.fill(visited, false);
		int groupNum = 0;

		// 역방향 그래프에 대하여 dfs를 수행
		// 이때,

		while (!stk.isEmpty()) {
			int start = stk.pop();

			if (visited[start]) {
				continue;
			}

			reDFS(start, groupNum++);
		}

		sb.append(groupNum + "\n");

		TreeMap<Integer, Integer> map = new TreeMap<>();
		for (int i = 0; i < groupNum; i++) {
			Collections.sort(ans[i]);
			map.put(ans[i].get(0), i);
		}

		map.keySet().forEach(key -> {
			int value = map.get(key);

			for(Integer v : ans[value]) {
				sb.append(v + " ");
			}
			sb.append("-1\n");
		});

		System.out.println(sb);
		
	}

	static void DFS(int cur) {

		visited[cur] = true;

		for (Integer next : diGraphs[cur]) {
			if (!visited[next]) {
				DFS(next);
			}
		}

		stk.push(cur);

	}

	static void reDFS(int cur, int groupNum) {

		visited[cur] = true;
		ans[groupNum].add(cur);

		for(Integer next : rdiGraphs[cur]) {
			if (!visited[next]) {
				reDFS(next, groupNum);
			}
		}
	}
}