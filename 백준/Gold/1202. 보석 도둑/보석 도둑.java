import java.util.*;
import java.io.*;

/**
 *packageName    : _250627
 * fileName       : BOJ_G2_1202_보석도둑
 * author         : moongi
 * date           : 6/27/25
 * description    :
 */
public class Main {
	static class Jewel implements Comparable<Jewel> {
		int weight, price;

		public Jewel(int weight, int price) {
			this.weight = weight;
			this.price = price;
		}

		@Override
		public int compareTo(Jewel o) {
			if (this.weight == o.weight) {
				return o.price - this.price;
			}
			return this.weight - o.weight;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken()); // 보석의 개수
		int K = Integer.parseInt(st.nextToken()); // 가방의 개수

		Jewel[] jewels = new Jewel[N];

		int M, V;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			M = Integer.parseInt(st.nextToken()); // 보석의 무게
			V = Integer.parseInt(st.nextToken()); // 보석의 가격
			jewels[i] = new Jewel(M, V);
		}

		Arrays.sort(jewels);

		int C;
		int[] bags = new int[K];
		for (int i = 0; i < K; i++) {
			bags[i] = Integer.parseInt(br.readLine()); // 가방의 무게
		}

		Arrays.sort(bags);

		// 조건
		// 1. 보석의 무게는 가방의 무게를 넘지 못한다.
		// 2. 가방 하나에는 보석 하나만 담을 수 있고, 이때 보석의 최대 가격을 구하는 문제

		// 가방의 무게를 정렬해서 가능한 보석을 모두 pq에 넣는다.
		// 이후 가방들은 공간이 이전보다 다 넉넉하기 때문에, 모두 수용가능할 것이기 때문이다.

		// 그래서 넣을 수 있는 보석을 다 넣고 각각의 가방에 대해 우선순위큐에 들어있는 가장 비싼
		// 보석을 하나 꺼내서 가방에 넣는다고 가정하고, 결과값을 갱신해준다.
		
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		long res = 0;

		for (int i = 0, j = 0; i < K; i++) {

			while(j < N && jewels[j].weight <= bags[i]) {
				pq.offer(jewels[j++].price);
			}

			if (!pq.isEmpty()) {
				res += pq.poll();
			}
		}

		System.out.println(res);

	}
}