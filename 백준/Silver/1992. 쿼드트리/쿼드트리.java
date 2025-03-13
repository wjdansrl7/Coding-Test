
import java.io.*;
import java.util.*;

public class Main {
	static int[][] arr;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		arr = new int[N][N];

		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < N; j++) {
				arr[i][j] = s.charAt(j) - '0';
			}
		}

		makeTree(0, 0, N);

		System.out.println(sb);
	}

	static void makeTree(int x, int y, int size) {

		if (isDivide(x, y, size)) {
			sb.append(arr[x][y]);
			return;
		}

		sb.append('(');

		int newSize = size / 2;

		makeTree(x, y, newSize);
		makeTree(x, y + newSize, newSize);
		makeTree(x + newSize, y, newSize);
		makeTree(x + newSize, y + newSize, newSize);

		sb.append(')');
	}

	static boolean isDivide(int x, int y, int size) {
		int cur = arr[x][y];

		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (cur != arr[i][j]) {
					return false;
				}
			}
		}

		return true;
	}
}