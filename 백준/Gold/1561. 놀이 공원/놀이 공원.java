import java.util.*;
import java.io.*;

/**
 *packageName    : _251007
 * fileName       : BOJ_G1_1561_놀이공원
 * author         : moongi
 * date           : 10/7/25
 * description    :
 *
 * 가장 마지막 아이가 타고 있는 놀이기구의 번호
 *
 * 1. 초기 모든 놀이기구는 비어있는 상태
 * 2. 줄에 서 있는 순서대로 놀이기구를 탄다.
 * 3. 놀이기구마다 운행 시간이 정해져있다.
 * 4. 만약 여러 놀이기구가 비어있다면, 가장 작은 번호의 놀이기구를 먼저 탑승한다.
 */
public class Main {
	static long n;
	static int m;
	static int[] time;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Long.parseLong(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		time = new int[m];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			time[i] = Integer.parseInt(st.nextToken());
		}

		if (n <= m) {
			System.out.println(n);
			return;
		}

		long result = binarySearch();
		// result 직전까지 탑승 완료된 인원 수
		long child = getChildNumInTime(result - 1);

		for (int i = 0; i < m; i++) {
			if (result % time[i] == 0) { // i번 놀이기구가 result 시점에 새로 탑승 가능한 상태
				child++; // 실제로 아이가 그 기구를 타며 전체 순번 1 증가
			}
			if (child == n) { // 바로 그 아이가 마지막(n번째)아이 -> 해당 기구 번호 출력
				System.out.println(i + 1);
				break;
			}
		}

	}

	private static long getChildNumInTime(long t) {
		long childNum = m;
		for (int i = 0; i < m; i++) {
			childNum += t / time[i];
		}

		return childNum;
	}

	private static long binarySearch() {
		long l = 0;
		long r = n * 30;

		while (l <= r) {
			long mid = (l + r) >> 1;
			long childNum = getChildNumInTime(mid);

			if (childNum < n) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		return l;

	}
}