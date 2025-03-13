
import java.util.*;
import java.io.*;


public class Main {
	static class Gift implements Comparable<Gift> {
		int restDay; // 남은 사용기한
		int useDay; // 사용할 예정의 날짜
		public Gift(int restDay, int useDay) {
			this.restDay = restDay;
			this.useDay = useDay;
		}

		public Gift(int restDay) {
			this.restDay = restDay;
		}

		public void set(int useDay) {
			this.useDay = useDay;
		}

		@Override
		public int compareTo(Gift o) {
			if (this.useDay == o.useDay) {
				return this.restDay - o.restDay;
			}

			return this.useDay - o.useDay;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());

		Gift[] gifts = new Gift[N]; // 사용해야할 기프티콘에 대한 정보

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			gifts[i] = new Gift(Integer.parseInt(st.nextToken()), i);
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			gifts[i].set(Integer.parseInt(st.nextToken()));
		}

		Arrays.parallelSort(gifts);

		int prev_max = gifts[0].useDay;
		int cur_max = -1;
		long answer = 0;

		for (int i = 0; i < N; i++) {
			if (prev_max > gifts[i].restDay) {

				// 이전 구간의 최댓값보다 기프티콘 사용날짜가 더 크다면 갱신한다.
				if (prev_max < gifts[i].useDay) {
					prev_max = gifts[i].useDay;
				}

				// 29를 더해주면 나머지가 1이상일 때, 몫을 1추가한 것과 같다.
				int cnt = ((prev_max - gifts[i].restDay) + 29) / 30;

				gifts[i].restDay += (cnt * 30);

				answer += cnt;
			}

			// 같은 구간의 최댓값 찾기
			cur_max = Math.max(cur_max, gifts[i].restDay);

			// 구간 변경 시 같은 구간 값 중 최댓값을 이전 값으록 갱신
			if ((i + 1) < N && gifts[i].useDay != gifts[i + 1].useDay) {
				prev_max = cur_max;
			}
		}

		System.out.println(answer);
	}
}
