
import java.util.*;
import java.io.*;

/**
 *packageName    : _251007
 * fileName       : BOJ_G4_11000_강의실배정
 * author         : moongi
 * date           : 10/7/25
 * description    :
 */
public class Main {
	static int N;

	static class Lecture implements Comparable<Lecture> {
		int start, end;

		public Lecture(int start, int end) {
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Lecture o) {

			if (this.start == o.end) {
				return this.end - o.end;
			}

			return this.start - o.start;
		}
	}

	static Lecture[] lectures;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());

		lectures = new Lecture[N];

		int ans = 0; // 강의실의 갯수

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			lectures[i] = new Lecture(Integer.parseInt(st.nextToken()),
				Integer.parseInt(st.nextToken()));
		}

		Arrays.sort(lectures);

		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.offer(lectures[0].end);

		for (int i = 1; i < N; i++) {

			if (pq.peek() <= lectures[i].start) {
				pq.poll();
			}

			pq.offer(lectures[i].end);
		}

		System.out.println(pq.size());
		
	}
}