
import java.util.*;
import java.io.*;

/**
 *packageName    : _251027
 * fileName       : BOJ_S2_19621_회의실배정2
 * author         : moongi
 * date           : 10/27/25
 * description    :
 */
public class Main {
	static class Room implements Comparable<Room> {
		int start, end, num;

		public Room(int start, int end, int num) {
			this.start = start;
			this.end = end;
			this.num = num;
		}

		@Override
		public int compareTo(Room o) {

			if (this.start == o.start) {

				if (this.end == o.end) {

					return o.num - this.num;
				}

				return this.end - o.end;
			}

			return this.start - o.start;
		}
	}

	static Room[] rooms;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());

		rooms = new Room[N];

		int start, end, num;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			num = Integer.parseInt(st.nextToken());

			rooms[i] = new Room(start, end, num);

		}

		Arrays.sort(rooms);

		int[] dp = new int[N];
		int max = 0;

		for (int i = 0; i < N; i++) {
			dp[i] = rooms[i].num;
			if (dp[i] > max) max = dp[i];
		}

		for (int i = 0; i < N; i++) {

			for (int j = i + 1; j < N; j++) {

				if (rooms[j].start >= rooms[i].end) {
					dp[j] = Math.max(dp[j], dp[i] + rooms[j].num);
					if (dp[j] > max) max = dp[j];
				}
			}
		}

		System.out.println(max);

	}
}