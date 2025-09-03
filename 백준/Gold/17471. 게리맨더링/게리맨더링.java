import java.util.*;
import java.io.*;

/**
 *packageName    : _250903
 * fileName       : BOJ_G3_17471_게리맨더링
 * author         : moongi
 * date           : 9/3/25
 * description    :
 *
 * 백준시의 정보가 주어졌을 때, 인구 차이의 최솟값
 *
 */
public class Main {
	static List<Integer>[] graphs;
	static int N, ans;
	static int[] people;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		ans = 1001;
		people = new int[N + 1];

		// 해당 구역의 인구수
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i < N + 1; i++) {
			people[i] = Integer.parseInt(st.nextToken());
		}

		graphs = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());

			int count = Integer.parseInt(st.nextToken());

			for (int j = 0; j < count; j++) {
				int region = Integer.parseInt(st.nextToken());

				graphs[i].add(region);
				graphs[region].add(i);
			}
		}

		// 선거구를 나눌 수 없는 경우, -1을 출력한다.

		for (int i = 1; i <= N / 2; i++) {
			// 지역구 선택
			List<Integer> regions = new ArrayList<>();
			boolean[] visited = new boolean[N + 1];
			comb(0, i, regions, visited);
		}

		System.out.println(ans == 1001 ? -1 : ans);


	}

	static int connected(List<Integer> lists) {
		// 연결된 총 인구수
		int sum = 0, cnt = 0, size = lists.size();

		boolean[] visited = new boolean[N + 1];
		int start = lists.get(0);
		visited[start] = true;

		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.offer(start);

		while (!q.isEmpty()) {
			int p = q.poll();
			// 연결된 노드 갯수
			cnt++;
			// 인구수 증가
			sum += people[p];

			for(Integer next : graphs[p]) {
				if (!visited[next] && lists.contains(next)) {
					q.offer(next);
					visited[next] = true;
				}
			}
		}

		if (cnt == size) {
			return sum;
		}

		return -1;
	}

	static void comb(int cnt, int max, List<Integer> regions, boolean[] visited) {

		if (cnt == max) {
			// 모든 지역구 선택 완료
			if (regions.size() == 0) return;

			int A = connected(regions);
			if (A > 0) {
				List<Integer> reverse = new ArrayList<>();

				for (int i = 1; i < N + 1; i++) {
					if (!regions.contains(i)) reverse.add(i);
				}

				if (reverse.size() == 0) return;

				int B = connected(reverse);
				if (B > 0) {
					int diff = Math.abs(A - B);
					if (ans > diff) {
						ans = diff;
					}
				}
			}

			return;
		}

		for (int i = 1; i < N + 1; i++) {
			if (visited[i]) continue;

			regions.add(i);
			visited[i] = true;
			comb(cnt+1, max, regions, visited);
			visited[i] = false;
			regions.remove(regions.size() - 1);
		}
	}
}