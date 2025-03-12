import java.io.*;
import java.util.*;

public class Main {
	static class Flower implements Comparable<Flower> {
		int start, end;

		public Flower(int start, int end) {
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Flower o) {
			if (this.start == o.start) {
				return o.end - this.end;
			}

			return this.start - o.start;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());

		int stM, stD, etM, etD;
		Flower[] flowers = new Flower[N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			stM = Integer.parseInt(st.nextToken()) * 100;
			stD = Integer.parseInt(st.nextToken());
			etM = Integer.parseInt(st.nextToken()) * 100;
			etD = Integer.parseInt(st.nextToken());

			flowers[i] = new Flower(stM + stD, etM + etD);
		}

		Arrays.parallelSort(flowers);

		int start = 301;
		int end = 1201;
		int count = 0;
		int idx = 0;
		int max = 0;

		while (start < end) {
			boolean isFinded = false; // 새로운 꽃을 방문했는지에 대한 여부

			for (int i = idx; i < N; i++) {

				// 모든 꽃들을 순회했을 떄, 해당 시작 날짜가 포함되어야하는 시작날짜 이후라면 반복문을 빠져나간다.
				if(flowers[i].start > start) {
					break;
				}

				if (max < flowers[i].end) {
					isFinded = true;
					max = flowers[i].end;
					idx = i + 1;
				}

			}

			if (isFinded) {
				start = max;
				count++;
			} else {
				break;
			}


		}

		if (max < end) {
			System.out.println(0);
		} else {
			System.out.println(count);
		}
	}
}
