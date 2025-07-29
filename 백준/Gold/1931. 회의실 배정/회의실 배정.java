import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_G5_1931_회의실배정
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	static class Meeting implements Comparable<Meeting> {

		int start, end;

		public Meeting(int start, int end) {
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Meeting o) {
			if (this.end == o.end) {
				return this.start - o.start;
			}

			return this.end - o.end;
		}
	}

	static Meeting[] meetings;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());

		meetings = new Meeting[N];

		int s, e;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());

			meetings[i] = new Meeting(s, e);

		}

		Arrays.sort(meetings);

		int ans = 1;
		int endTime = meetings[0].end;
		for (int i = 1; i < N; i++) {
			if (meetings[i].start >= endTime) {
				ans++;
				endTime = meetings[i].end;
			}
		}

		System.out.println(ans);

	}
}