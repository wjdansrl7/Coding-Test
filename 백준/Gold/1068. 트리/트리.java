
import java.util.*;
import java.io.*;
/**
 *packageName    : _250807
 * fileName       : BOJ_G5_1068_트리
 * author         : moongi
 * date           : 8/7/25
 * description    :
 */
public class Main {
	static boolean[] visited;
	static List<Integer>[] nodes;
	static int ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		ans = 0;

		nodes = new List[N];
		for (int i = 0; i < N; i++) {
			nodes[i] = new ArrayList<>();
		}

		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			int parent = Integer.parseInt(st.nextToken());

			if (parent == -1) {
				continue;
			}

			nodes[parent].add(i);
		}

		visited = new boolean[N];

		int M = Integer.parseInt(br.readLine());

		DFS(M);

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			
			int tmp = 0;
			for(Integer value : nodes[i]) {
				if (visited[value]) continue;
				tmp++;
			}

			if(nodes[i].isEmpty() || tmp == 0) ans++;
		}
		System.out.println(ans);
	}

	static void DFS(int curr) {

		visited[curr] = true;

		for(Integer next : nodes[curr]) {
			if (!visited[next]) {
				DFS(next);
			}
		}
	}
}