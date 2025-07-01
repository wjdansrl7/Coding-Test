
import java.util.*;
import java.io.*;
/**
 *packageName    : _250701
 * fileName       : BOJ_S5_2751_수정렬하기2
 * author         : moongi
 * date           : 7/1/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<>();

		for (int i = 0; i < N; i++) {
			pq.offer(Integer.parseInt(br.readLine()));
		}

		while (!pq.isEmpty()) {
			sb.append(pq.poll()).append('\n');
		}

		System.out.println(sb);
	}
}