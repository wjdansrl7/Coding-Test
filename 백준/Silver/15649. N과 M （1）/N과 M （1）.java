
import java.util.*;
import java.io.*;

/**
 *packageName    : _260404
 * fileName       : BOJ_S3_15649_N과M1
 * author         : moongi
 * date           : 4/4/26
 * description    :
 */
public class Main {
	static StringBuilder sb = new StringBuilder();;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		boolean[] visited = new boolean[N + 1];
		ArrayList<Integer> list = new ArrayList<>();
		comb(N, M, 0, visited, list);

		System.out.println(sb);
	}

	static void comb(int N, int M, int cnt, boolean[] visited, List<Integer> list) {
		if (cnt == M) {
			for (Integer nxt : list) sb.append(nxt).append(' ');
			sb.append('\n');
			return;
		}

		for (int i = 1; i < N + 1; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			list.add(i);
			comb(N, M, cnt + 1, visited, list);
			list.remove(list.size() - 1);
			visited[i] = false;
		}
	}
}