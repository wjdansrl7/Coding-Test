
import java.util.*;
import java.io.*;

public class Main {
	static class Brick implements Comparable<Brick> {
		int idx;
		int width, height, weight;

		public Brick(int idx, int width, int height, int weight) {
			this.idx = idx;
			this.width = width;
			this.height = height;
			this.weight = weight;
		}

		@Override
		public int compareTo(Brick o) {
			return this.weight - o.weight;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		List<Brick> bricks = new ArrayList<>();
		bricks.add(new Brick(0, 0, 0, 0));

		int a, b, c;
		for (int i = 1; i < N + 1; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			bricks.add(new Brick(i, a, b, c));

		}

		// 무게 순으로 오름차순 정렬
		Collections.sort(bricks);

		// 해당 벽돌을 넣었을 때, 나올 수 있는 최대의 높이
		int[] dp = new int[N + 1];

		for (int i = 1; i < N + 1; i++) {

			for (int j = 0; j < i; j++) {

				// 현재 벽돌의 밑면의 넓이가 더 크다면
				if (bricks.get(i).width > bricks.get(j).width) {
					dp[i] = Math.max(dp[i], dp[j] + bricks.get(i).height);
				}

			}
		}

		// 내가 해결하지 못했던 부분.
		// TODO: 역순으로 사용했던 벽돌을 찾아야 함.

		int maxHeight = -1;

		for (int i = 1; i < N + 1; i++) {
			if (maxHeight < dp[i])
				maxHeight = dp[i];
		}

		int idx = N;
		List<Integer> res = new ArrayList<>();

		while (idx != 0) {
			if (maxHeight == dp[idx]) {
				res.add(bricks.get(idx).idx);
				maxHeight -= bricks.get(idx).height;
			}
			idx--;
		}

		StringBuilder sb = new StringBuilder();
		sb.append(res.size()).append('\n');

		for (int i = res.size()-1; i >= 0; i--) {
			sb.append(res.get(i)).append('\n');
		}
		System.out.println(sb);
		
	}
}