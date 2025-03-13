
import java.util.*;
import java.io.*;

public class Main {
	static int[][] arr;
	static int[] count;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		// white: 0, blue: 1

		int N = Integer.parseInt(br.readLine());
		arr = new int[N][N];
		count = new int[2];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		makePaper(0, 0, N);

		System.out.println(count[0]);
		System.out.println(count[1]);
	}

	static void makePaper(int x, int y, int size) {
		if (cuttable(x, y, size)) {
			if (arr[x][y] == 0)
				count[0]++;
			else
				count[1]++;
			return;
		}

		int newSize = size / 2;

		makePaper(x, y, newSize);
		makePaper(x, y + newSize, newSize);
		makePaper(x + newSize, y, newSize);
		makePaper(x + newSize, y + newSize, newSize);
	}

	static boolean cuttable(int x, int y, int size) {
		int cur = arr[x][y];

		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (cur != arr[i][j])
					return false;
			}
		}
		return true;
	}
}
