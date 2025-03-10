
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		Set<Integer> set = new HashSet<>();

		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				set.add(arr[i] + arr[j]);
			}
		}

		int res = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int target = arr[i] - arr[j];
				if (set.contains(target)) {
					res = Math.max(res, arr[i]);
				}
			}
		}
		
		System.out.println(res);

	}
}
