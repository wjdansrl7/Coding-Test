
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		Map<Integer, Integer> map = new HashMap<>();

		int start, end;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());

			map.put(start, map.getOrDefault(start, 0) + 1);
			map.put(end, map.getOrDefault(end, 0) - 1);

		}

		PriorityQueue<Integer> pq = new PriorityQueue<>(map.keySet());

		boolean flag = false;
		int sum = 0, res = 0;
		int left = 0, right = 0;
		while (!pq.isEmpty()) {

			int curr = pq.poll();
			sum += map.get(curr);

			if (sum > res) {
				res = sum;
				left = curr;
				flag = true;
			} else if (sum < res && flag) {
				right = curr;
				flag = false;
			}
		}

		System.out.println(res);
		System.out.println(left + " " + right);
	}
}
