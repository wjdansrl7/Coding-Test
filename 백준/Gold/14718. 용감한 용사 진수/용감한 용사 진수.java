
import java.sql.SQLOutput;
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken()); // 병사 수
		int K = Integer.parseInt(st.nextToken()); // 이겨야 하는 인원

		int[][] arr = new int[N][3];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
			arr[i][2] = Integer.parseInt(st.nextToken());
		}

		int res = 3_000_001;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {

					int cnt = 0;
					for (int l = 0; l < N; l++) {
						if (arr[i][0] >= arr[l][0] && arr[j][1] >= arr[l][1] && arr[k][2] >= arr[l][2]) {
							cnt++;
						}
					}

					if (cnt >= K) {
						res = Math.min(res, arr[i][0] + arr[j][1] + arr[k][2]);
					}
				}
			}
		}

		System.out.println(res);


	}
}
