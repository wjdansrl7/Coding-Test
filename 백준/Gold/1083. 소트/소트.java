
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int S = Integer.parseInt(br.readLine());

		for (int i = 0; i < N && S > 0; i++) {
			
			int max = arr[i];
			int idx = -1;

			for (int j = i + 1; j < N && j <= i + S; j++) {
				if (arr[j] > max) {
					max = arr[j];
					idx = j;
				}
			}

			if (idx == -1)
				continue;

			S -= idx - i;

			for (int j = idx; j >= i + 1; j--) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}

		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < N; i++) {
			sb.append(arr[i]).append(' ');
		}
		System.out.println(sb);
	}
}
