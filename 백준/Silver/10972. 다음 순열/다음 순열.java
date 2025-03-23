
import java.util.*;
import java.io.*;

public class Main {
	static int N;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		int[] arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		StringBuilder sb = new StringBuilder();
		if (!nextPermutation(arr))
			System.out.println(-1);
		else {
			for (int i = 0; i < N; i++) {
				sb.append(arr[i]).append(' ');
			}
			sb.append('\n');
		}
		System.out.println(sb);


	}

	static boolean nextPermutation(int[] arr) {

		int i = arr.length - 1;

		// 1. arr[i-1] < arr[i] 를 만족하는 가장 큰 i를 찾는다.
		while (i > 0 && arr[i - 1] >= arr[i]) {
			i--;
		}

		// 정렬이 완료된 경우
		if (i <= 0) return false;

		int j = arr.length - 1;

		// 2. j >= i 이면서 A[j] > A[i-1] 를 만족하는 j를 찾는다.
		while (arr[i - 1] >= arr[j]) {
			j--;
		}

		// 3. arr[i-1]과 arr[j] swap
		int tmp = arr[j];
		arr[j] = arr[i - 1];
		arr[i - 1] = tmp;

		j = arr.length - 1;

		// arr[i]부터 순열을 뒤집는다.
		while (i < j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}

		return true;
	}
}