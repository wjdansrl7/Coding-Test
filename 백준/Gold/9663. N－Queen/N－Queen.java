
import java.io.*;

public class Main {
	static int res, N;
	static int[] pos;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		pos = new int[N];
		res = 0;

		nQueen(0);

		System.out.println(res);
	}

	static void nQueen(int row) {
		if (row == N) {
			res++;
			return;
		}

		for (int col = 0; col < N; col++) {
			if (valid(row, col)) {
				pos[row] = col;
				nQueen(row + 1);
			}
		}
	}

	static boolean valid(int row, int col) {
		for (int i = 0; i < row; i++) {
			if (pos[i] == col || Math.abs(row - i) == Math.abs(pos[i] - col)) {
				return false;
			}
		}
		return true;
	}
}