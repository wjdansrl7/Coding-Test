import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		int[] height = new int[N];
		int max = 0;

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		// 이전 기울기보다 작아지면
		for (int i = 0; i < N; i++) {
			double curve = Double.MAX_VALUE;
            for (int j = i-1; j >= 0; j--) {
                if (curve > (double) (arr[i] - arr[j]) / (i - j)) {
                    curve = (double) (arr[i] - arr[j]) / (i - j);
                    height[i]++;
                }
            }

            curve = -Double.MAX_VALUE;
            for (int j = i+1; j < N; j++) {
                if (curve < (double) (arr[j] - arr[i]) / (j - i)) {
                    curve = (double) (arr[j] - arr[i]) / (j - i);
                    height[i]++;
                }
            }

			if (height[i] > max) {
				max = height[i];
			}
		}

		System.out.println(max);
	}
}