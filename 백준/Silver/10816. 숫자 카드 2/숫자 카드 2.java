import java.io.*;
import java.util.*;

/**
 *packageName    : _250730
 * fileName       : BOJ_S4_10816_숫자카드2
 * author         : moongi
 * date           : 7/30/25
 * description    :
 * 
 * 항상 헷갈리는 부분 정리 !!! 초기에 res를 배열의 길이만큼 초기화한 상태에서 문제를 풀어준다.
 * lowerBound: 항상 arr[mid] < target → lo가 arr.length가 될 때 종료 → res = arr.length
 * upperBound: 항상 arr[mid] <= target → lo가 arr.length가 될 때 종료 → res = arr.length
 */
public class Main {
	static int[] arr;
	static int N, M;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(arr);

		M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < M; i++) {
			int target = Integer.parseInt(st.nextToken());
            
			sb.append(upperBound(target, 0, N - 1) - lowerBound(target, 0, N - 1)).append(" ");
		}

		System.out.println(sb);
	}

	static int upperBound(int target, int start, int end) {

		int res = arr.length;

		while (start <= end) {

			int mid = (start + end) >> 1;

			if (arr[mid] > target) {
				res = mid;
				end = mid - 1;
			} else {
				start = mid + 1;

			}
		}

		return res;

	}

	static int lowerBound(int target, int start, int end) {

		int res = arr.length;
		while (start <= end) {

			int mid = (start + end) >> 1;

			if (arr[mid] >= target) {
				res = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		return res;
	}
}
