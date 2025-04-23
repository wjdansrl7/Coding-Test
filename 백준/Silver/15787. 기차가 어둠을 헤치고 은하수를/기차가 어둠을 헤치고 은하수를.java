import java.util.*;
import java.io.*;

public class Main {
	static int N, M;
	static Map<Long, Integer> map;
	static long[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		// 존재하는 위치를 저장한다.
		map = new HashMap<>();
		arr = new long[N + 1];

		int mode, trail, idx = 0;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			mode = Integer.parseInt(st.nextToken());
			trail = Integer.parseInt(st.nextToken());
			if (mode == 1 || mode == 2) idx = Integer.parseInt(st.nextToken());

			command(mode, trail, idx);
		}

		for (int i = 1; i < N+1; i++) {
			map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
		}

		System.out.println(map.size());

	}

	static void command(int mode, int trail, int idx) {

		if (mode == 1) {
			arr[trail] |= (1 << idx-1);
		} else if (mode == 2) {
			arr[trail] &= ~(1 << (idx-1));
		} else if (mode == 3) {
			arr[trail] = arr[trail] << 1 & 0xfffff;

		} else if (mode == 4){
			arr[trail] >>= 1;
		}

	}
}