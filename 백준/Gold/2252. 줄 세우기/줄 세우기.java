import java.util.*;
import java.io.*;

/**
 *packageName    : _250810
 * fileName       : BOJ_G3_2252_줄세우기
 * author         : moongi
 * date           : 8/10/25
 * description    :
 * 위상 정렬: 그래프에서 선후관계 조건이 있을 때, 이를 고려해서 노드의 순서를 정렬할 수 있다.
 * 위상 정렬의 조건
 * DAG(Directed Acyclic Graph, 방향성이 있으며 사이클이 없는 그래프)
 * DFS를 사용하여 구현하거나, indegree 배열을 사용하여 구현한다.
 *
 */
public class Main {
	static int N, M;
	static List<Integer>[] graphs;
	static int[] indegree;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken()); // 학생 수
		M = Integer.parseInt(st.nextToken()); // 비교 횟수

		graphs = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		indegree = new int[N + 1];

		for (int i = 0; i < M; i++) {
			// 키 비교: A < B
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());

			graphs[A].add(B);
			indegree[B]++;
		}

		ArrayDeque<Integer> q = new ArrayDeque<>();

		for (int i = 1; i < N + 1; i++) {
			// 진입차수가 0인 노드에 대하여 queue 삽입
			if (indegree[i] == 0)
				q.offer(i);
		}

		StringBuilder sb = new StringBuilder();

		while (!q.isEmpty()) {

			int p = q.poll();

			sb.append(p + " ");

			for(Integer next : graphs[p]) {
				indegree[next]--;

				if (indegree[next] == 0) {
					q.offer(next);
				}
			}
		}

		System.out.println(sb);
	}
}