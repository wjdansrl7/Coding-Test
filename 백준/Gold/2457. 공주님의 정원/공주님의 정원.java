import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_G3_2457_공주님의정원
 * author         : moongi
 * date           : 7/29/25
 * description    :
 *
 * 0301 - 1130 매일 한 가지 꽃이 피어있도록 한다.
 * 정원이 넓지 않으므로, 최대한 적은 수를 심는다.
 *
 * end asc, start desc
 */
public class Main {
	static class Flower implements Comparable<Flower> {
		int start, end;

		public Flower(int start, int end) {
			this.start = start;
			this.end = end;
		}

		// start asc, end desc
		@Override
		public int compareTo(Flower f) {

			if (this.start == f.start) {
				return f.end - this.end;
			}

			return this.start - f.start;
		}
	}

	static Flower[] flowers;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		flowers = new Flower[N];

		int sm, sd, em, es;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			sm = Integer.parseInt(st.nextToken());
			sd = Integer.parseInt(st.nextToken());
			em = Integer.parseInt(st.nextToken());
			es = Integer.parseInt(st.nextToken());

			flowers[i] = new Flower(sm * 100 + sd, em * 100 + es);

		}

		Arrays.sort(flowers);

		int startDay = 301, endDay = 1201, idx = 0, max = 0, cnt = 0;

		while (startDay < endDay) {

			boolean isOpen = false; // 새로운 꽃을 찾았는지 여부 판단

			for (int i = idx; i < N; i++) {

				if (flowers[i].start > startDay) { // 종료일보다 시작일이 이후면 빈 공간이 생김
					break;
				}
					
				// 최대한 정렬된 꽃들을 순회하면서 최소한으로 모든 날들을 커버 가능한 것까지 탐색한다.
				if (max < flowers[i].end) {
					isOpen = true;
					max = flowers[i].end; // 해당 날짜까지 꽃이 피어있음.
					idx = i + 1; // 다음 꽃으로 이동한다.
				}
			}

			// 새로운 꽃을 한 번이라도 발견한 경우, 해당 종료날짜를 시작 날짜로 갱신하고, 꽃의 개수를 추가해준다.
			if (isOpen) {
				startDay = max;
				cnt++;
			} else {
				break;
			}

		}

		if (max < endDay) {
			System.out.println(0);
		} else {
			System.out.println(cnt);
		}
	}
}