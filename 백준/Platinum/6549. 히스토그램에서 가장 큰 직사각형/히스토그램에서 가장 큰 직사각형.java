import java.io.*;
import java.util.*;

/**
 *packageName    : _250501
 * fileName       : BOJ_P5_6549_히스토그램에서가장큰직사각형
 * author         : moongi
 * date           : 5/1/25
 * description    :
 */
public class Main {
	static int[] histogram;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int N;
		while (true) {

			st = new StringTokenizer(br.readLine());

			N = Integer.parseInt(st.nextToken());

			if (N == 0) break;

			histogram = new int[N];

			for (int i = 0; i < N; i++) {
				histogram[i] = Integer.parseInt(st.nextToken());
			}

			sb.append(getArea(0, N - 1)).append('\n');
			histogram = null;
		}

		System.out.println(sb);
	}

	/**
	 * 분할 정복 기법을 사용하여 오른쪽과 왼쪽 구간에서 가장 큰 넓이의 영역을 구한다.
	 * @param lo
	 * @param hi
	 * @return
	 * 
	 * 1. 가운데 위치를 구한다.(mid = (lo + hi) >> 1)
	 * 2. 가운데 위치를 기준으로 분할하여 왼쪽 구간의 넓이([lo:mid])와 오른쪽 구간의 넓이([mid:hi])를 구한다.
	 * 3. 왼쪽과 오른쪽 중 큰 넓이를 변수에 저장한다.
	 * 4. 변수에 저장된 넓이와 두 구간을 합친 구간([lo:hi])의 가장 큰 넓이를 구해 두 개 중 가장 큰 넓이를 반환한다.
	 */
	static long getArea(int lo, int hi) {

		// 막대 폭이 1인 경우, 높이가 넓이가 되므로 바로 반환한다.
		if (lo == hi) {
			return histogram[lo];
		}

		// [1번 과정]		
		int mid = (lo + hi) >> 1;

		/**
		 * [2번 과정]
		 * mid를 기점으로 양쪽으로 나누어 양쪽 구간 중 큰 넓이를 저장
		 * 왼쪽 부분: lo ~ mid
		 * 오른쪽 부분: mid+1 ~ hi
		 */
		long leftArea = getArea(lo, mid);
		long rightArea = getArea(mid + 1, hi);
		
		// [3번 과정]
		long max = Math.max(leftArea, rightArea);

		// [4번 과정]
		// 양쪽 구간 중 큰 값과 중간 구간을 비교하여 더 큰 넓이로 갱신
		max = Math.max(max, getMidArea(lo, hi, mid));

		return max;
	}

	// 중간지점 영역의 넓이를 구하는 메소드
	private static long getMidArea(int lo, int hi, int mid) {

		int toLeft = mid; // 중간 지점으로부터 왼쪽으로 갈 변수
		int toRight = mid; // 중간 지점으로부터 오른쪽으로 갈 변수

		long height = histogram[mid]; // 높이

		long maxArea = height;

		while (lo < toLeft && toRight < hi) {

			/**
			 * 양쪽 다음칸의 높이 중 높은 값을 선택하되,
			 * 갱신되는 height는 기존 height보다 작거나 같아야 한다.
			 */

			if (histogram[toLeft - 1] < histogram[toRight + 1]) {
				toRight++;
				height = Math.min(height, histogram[toRight]);
			} else {
				toLeft--;
				height = Math.min(height, histogram[toLeft]);
			}

			maxArea = Math.max(maxArea, height * (toRight - toLeft + 1));
		}

		while (toRight < hi) {
			toRight++;
			height = Math.min(height, histogram[toRight]);
			maxArea = Math.max(maxArea, height * (toRight - toLeft + 1));
		}

		while (lo < toLeft) {
			toLeft--;
			height = Math.min(height, histogram[toLeft]);
			maxArea = Math.max(maxArea, height * (toRight - toLeft + 1));
		}

		return maxArea;
	}
}