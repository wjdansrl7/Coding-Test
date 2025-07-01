
import java.util.*;
import java.io.*;
/**
 *packageName    : _250701
 * fileName       : BOJ_S2_11279_최대힙
 * author         : moongi
 * date           : 7/1/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(o2, o1);
			}
		});

		int target;
		for (int i = 0; i < N; i++) {
			target = Integer.parseInt(br.readLine());

			if (target == 0) {
				if (!maxHeap.isEmpty()) sb.append(maxHeap.poll()).append('\n');
				else sb.append(0).append('\n');
			} else {
				maxHeap.offer(target);
			}
		}

		System.out.println(sb);
	}
}