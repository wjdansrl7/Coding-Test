
import java.io.*;
import java.util.*;

/**
 *packageName    : _260217
 * fileName       : BOJ_S1_6236_용돈관리
 * author         : moongi
 * date           : 2/17/26
 * description    :
 * 현우는 N 일동안 돈을 사용
 * 인출은 M번만 할 수 있음
 * 한 번 꺼낼때 최소한의 K를 알고 싶다.
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		// 매일 사용할 금액
		int[] used = new int[N];
		// right: 한 번 인출한 금액의 최댓값
		int left = 1, right = 1_000_000_000;
		for (int i = 0; i < N; i++) {
			used[i] = Integer.parseInt(br.readLine());
			left = used[i] > left ? used[i] : left;
		}

		int K = 0;
		while (left <= right) {

			int mid = (left + right) >> 1;

			if ((getWithDrawalCount(mid, used)) <= M) {
				K = mid;
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		System.out.println(K);
	}

	static int getWithDrawalCount(int withDrawalAmount, int[] used) {
		int count = 1;
		int money = withDrawalAmount;

		for (int i : used) {
			money -= i;

			if (money < 0) {
				count++;
				money = withDrawalAmount - i;
			}
		}

		return count;
	}
}