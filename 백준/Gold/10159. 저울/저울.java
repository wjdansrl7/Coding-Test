
import java.util.*;
import java.io.*;
/**
 *packageName    : _250514
 * fileName       : BOJ_G4_10159_저울
 * author         : moongi
 * date           : 5/14/25
 * description    :
 *
 * 자신보다 큰 정렬과 작은 정렬을 각각 저장해서 거길 따라가면 되겠다.
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());

		List<Integer>[] smaller = new List[N + 1];
		List<Integer>[] larger = new List[N + 1];

		for (int i = 0; i < N + 1; i++) {
			smaller[i] = new ArrayList<>();
			larger[i] = new ArrayList<>();
		}

		int a, b;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			// a > b
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			smaller[a].add(b);
			larger[b].add(a);
		}

		boolean[] visited;
		ArrayDeque<Integer> q = new ArrayDeque<>();

		for (int i = 1; i < N + 1; i++) {
			visited = new boolean[N + 1];
			q.push(i);
			visited[i] = true;

			// 자신보다 작은 무게들에 대하여 비교할 수 있는 개수 구하기
			while (!q.isEmpty()) {
				int curr = q.pop();

				for (Integer nxt : smaller[curr]) {
					if (visited[nxt]) continue;
					visited[nxt] = true;
					q.push(nxt);
				}
			}

			q.push(i);

			// 자신보다 큰 무게들에 대하여 비교할 수 있는 개수 구하기
			while (!q.isEmpty()) {
				int curr = q.pop();

				for (Integer nxt : larger[curr]) {
					if (visited[nxt]) continue;
					visited[nxt] = true;
					q.offer(nxt);
				}
			}

			int count = 0;
			for (int j = 1; j < N + 1; j++) {
				if (visited[j]) count++;
			}

			sb.append(N - count).append('\n');
		}

		System.out.println(sb);

	}
}