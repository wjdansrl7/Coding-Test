
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int[] sum = new int[N / 2 + 1];
		int[] sum2 = new int[N / 2 + 1];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i < N / 2 + 1; i++) {
			sum[i] = sum[i - 1] + Integer.parseInt(st.nextToken());
			sum2[i] = sum2[i - 1] + Integer.parseInt(st.nextToken());
		}

		int res = sum[N / 2];
		int tmp;

		for (int i = 0; i < N; i++) {

			// 정훈이의 차례에서 밑장빼기를 하는 경우
			if (i % 2 == 1) {
				tmp = sum[i / 2] + sum2[N / 2] - sum2[i / 2];
			}
			// 상대 차례에서 밑장빼기를 하는 경우
			else {
				tmp = sum[i / 2 + 1] + sum2[N / 2 - 1] - sum2[i / 2];
			}
			res = res < tmp ? tmp : res;
		}

		System.out.println(res);
	}
}
