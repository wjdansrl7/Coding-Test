
import java.io.*;
import java.util.*;
/**
 *packageName    : _250703
 * fileName       : BOJ_S5_11728_배열합치기
 * author         : moongi
 * date           : 7/5/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		PriorityQueue<Integer> pq = new PriorityQueue<>();

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			pq.offer(Integer.parseInt(st.nextToken()));
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			pq.offer(Integer.parseInt(st.nextToken()));
		}

		while (!pq.isEmpty()) {
			sb.append(pq.poll()).append(" ");
		}

		System.out.println(sb);
	}
}