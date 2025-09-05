
import java.io.*;
import java.util.*;
/**
 *packageName    : _250905
 * fileName       : BOJ_S3_15649_N과M1
 * author         : moongi
 * date           : 9/5/25
 * description    :
 */
public class Main {
	static int N, M;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		boolean[] visited = new boolean[N + 1];
		List<Integer> li = new ArrayList<>();
		comb(0, visited, li);

		System.out.println(sb);
	}

	static void comb(int cnt, boolean[] visited, List<Integer> li) {

		if (cnt == M) {
			for (Integer v : li) sb.append(v).append(" ");
			sb.append('\n');
			return;
		}

		for (int i = 1; i < N + 1; i++) {
			if (visited[i]) continue;

			visited[i] = true;
			li.add(i);
			comb(cnt + 1, visited, li);
			li.remove(li.size() - 1);
			visited[i] = false;
		}
	}
}