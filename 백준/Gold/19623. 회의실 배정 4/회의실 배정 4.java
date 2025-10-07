import java.util.*;
import java.io.*;

/**
 *packageName    : _251007
 * fileName       : BOJ_G3_19623_회의실배정4
 * author         : moongi
 * date           : 10/7/25
 * description    : 회의실에서 진행할 수 있는 최대 인원을 출력
 *
 * binary search
 * first => 처음으로 조건을 만족하는 원소
 *
 *
 * last => 조건을 만족하는 마지막 원소
 */
public class Main {
	static int N;

	static class Meeting implements Comparable<Meeting> {
		int start, end, num;

		public Meeting(int start, int end, int num) {
			this.start = start;
			this.end = end;
			this.num = num;
		}

		@Override
		public int compareTo(Meeting o) {

			return this.end - o.end;
		}
	}

	static Meeting[] meetings;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine()); // N <= 100_000

		meetings = new Meeting[N+1];
		meetings[0] = new Meeting(0, 0, 0);

		int start, end, num;
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());

			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			num = Integer.parseInt(st.nextToken());

			meetings[i] = new Meeting(start, end, num);
		}

		// 회의 시간을 종료 시간으로 정렬
		// [50, 60, 100, 120, 140]
		Arrays.sort(meetings);

		// [종료시간 순 현재까지 고려한 회의의 idx] => 종료시간 순 0~i번 중 진행한 회의들의 인원수 합
		int[] dp = new int[N + 1];
		dp[0] = 0;

		for (int i = 1; i <= N; i++) {
			// 회의를 진행 시, 최적해는 회의가 시작되기 전까지 고를 수 있는 최적해에 회의의 인원수를 더한 값
			// 회의를 진행하지 않을 시, 최적해는 이전 회의의 최적해와 같다.

			// 회의 시작 전까지 진행할 수 있는 회의 중 가장 마지막 회의의 idx를 찾자.
			// 인덱스 0을 가상의 (0,0,0) 회의로 하였으므로 idx >= 0 임이 보장
			// 예를 들어 종료 시간이 [50, 60, 100, 120, 140]이고 회의 i의 시작시간이 90이라 하면
			// 구하는 idx는 1이다.
			int lo = 0;
			int hi = N;

			while (lo <= hi) {

				int mid = (lo + hi) >> 1;

				// 회의 i 시작 전까지 회의 마치기 불가능
				if (meetings[mid].end > meetings[i].start) {
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			dp[i] = Math.max(dp[hi] + meetings[i].num, dp[i - 1]);
		}

		System.out.println(dp[N]);

	}
}