
import java.io.*;
import java.util.*;

public class Main {
	static int N, S;
	static int[] arr;
	static List<Long> left, right;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());

		left = new ArrayList<>();
		right = new ArrayList<>();

		arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		partialSum(0, N / 2, 0, left);
		partialSum(N / 2, N, 0, right);

		Collections.sort(left);
		Collections.sort(right);

		sb.append(getCnt());

		System.out.println(sb);

	}

	static long getCnt() {

		int st = 0;
		int et = right.size() - 1;
		long res = 0;

		while (st < left.size() && et >= 0) {

			long sum = left.get(st) + right.get(et);

			if (sum == S) {
				long a = left.get(st);
				long cnt1 = 0;

				while (st < left.size() && left.get(st) == a) {
					cnt1++;
					st++;
				}

				long b = right.get(et);
				long cnt2 = 0;

				while (et >= 0 && right.get(et) == b) {
					cnt2++;
					et--;
				}

				res += cnt1 * cnt2;
			} else if (sum < S) {
				st++;
			} else {
				et--;
			}
		}

		if (S == 0) res--;

		return res;
	}
	static void partialSum(int start, int end, long sum, List<Long> list) {

		if (start == end) {
			list.add(sum);
			return;
		}

		partialSum(start + 1, end, sum, list);
		partialSum(start + 1, end, sum + arr[start], list);
	}
}