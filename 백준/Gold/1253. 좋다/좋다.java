
import java.io.*;
import java.util.*;

/**
 *packageName    : _250514
 * fileName       : BOJ_G4_1253_좋다
 * author         : moongi
 * date           : 5/14/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		int res = 0;

		for (int i = 0; i < N; i++) {
			int left = 0;
			int right = N - 1;
			while (true) {

				if (left == i) left++;
				else if (right == i) right--;

				if (left >= right) break;

				int target = arr[left] + arr[right];
				if (target > arr[i]) right--;
				else if (target < arr[i]) left++;
				else {
					res++;
					break;
				}
			}
		}

		System.out.println(res);
	}
}