
import java.util.*;
import java.io.*;

/**
 *packageName    : _250517
 * fileName       : BOJ_G5_16935_배열돌리기3
 * author         : moongi
 * date           : 5/17/25
 * description    :
 */
public class Main {
	static int N, M, K;
	static int[][] board;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		board = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(br.readLine());

		int[][] res = copyArr(board);
		int cnt = 0;
		for (int i = 0; i < K; i++) {
			int oper = Integer.parseInt(st.nextToken());

			if (oper == 1) res =op1(res);
			else if (oper == 2) res = op2(res);
			else if (oper == 3) {
				res = op3(res);
				cnt++;
			}
			else if (oper == 4) {
				res = op4(res);
				cnt++;
			}
			else if (oper == 5) res = op5(res);
			else if (oper == 6) res = op6(res);
		}

		StringBuilder sb = new StringBuilder();
		if (cnt % 2 == 0) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					sb.append(res[i][j] + " ");
				}
				sb.append('\n');
			}
		} else {
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					sb.append(res[i][j] + " ");
				}
				sb.append('\n');
			}
		}

		System.out.println(sb);
	}

	static int[][] copyArr(int[][] arr) {
		int[][] copied = new int[N][M];

		for (int i = 0; i < N; i++) {
			copied[i] = arr[i].clone();
		}

		return copied;
	}

	static int[][] op1(int[][] arr) {
		int[][] copied = new int[arr.length][arr[0].length];

		int idx = arr.length - 1;
		for (int i = 0; i < arr.length; i++) {
			copied[i] = arr[idx--].clone();
		}

		return copied;
	}

	static int[][] op2(int[][] arr) {
		int[][] copied = new int[arr.length][arr[0].length];

		// 순서 바꿨을 떄, N, M 바뀌는 거 유의하고.
		for (int i = 0, k = arr[0].length - 1; i < arr[0].length && k >= 0; i++, k--) {
			for (int j = 0; j < arr.length; j++) {
				copied[j][k] = arr[j][i];
			}
		}

		return copied;
	}


	// 배열의 크기가 변경됨.
	static int[][] op3(int[][] arr) {
		int[][] copied = new int[arr[0].length][arr.length];

		for (int i = 0, k = copied[0].length - 1; i < arr.length && k >= 0; i++, k--) {
			for (int j = 0, l = 0; j < arr[0].length && l < copied.length; j++, l++) {
				copied[l][k] = arr[i][j];
			}
		}

		return copied;

	}

	static int[][] op4(int[][] arr) {

		int[][] copied = new int[arr[0].length][arr.length];

		for (int i = 0, k = 0; i < arr.length && k < copied[0].length; i++, k++) {
			for (int j = arr[0].length-1, l = 0; j >=0 && l < copied.length; j--, l++) {
				copied[l][k] = arr[i][j];
			}
		}

		return copied;

	}

	static int[][] op5(int[][] arr) {
		int[][] copied = new int[arr.length][arr[0].length];
		int N = arr.length;
		int M = arr[0].length;
		
		// 4 -> 1
		for (int i = N / 2, k = 0; i < N && k < N / 2; i++, k++) {
			for (int j = 0, l = 0; j < M / 2 && l < M / 2; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}
		// 3 -> 4
		for (int i = N / 2, k = N/2; i < N && k < N; i++, k++) {
			for (int j = M / 2, l = 0; j < M && l < M / 2; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}

		// 2 -> 3
		for (int i = 0, k = N/2; i < N / 2 && k < N; i++, k++) {
			for (int j = M / 2, l = M / 2; j < M && l < M; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}

		// 1 -> 2
		for (int i = 0, k = 0; i < N / 2 && k < N / 2; i++, k++) {
			for (int j = 0, l = M / 2; j < M / 2 && l < M; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}

		return copied;
	}

	static int[][] op6(int[][] arr) {
		int[][] copied = new int[arr.length][arr[0].length];
		int N = arr.length;
		int M = arr[0].length;
			
		// 2, 3
		// 1 -> 4
		for (int i = 0, k = N/2; i < N / 2 && k < N; i++, k++) {
			for (int j = 0, l = 0; j < M / 2 && l < M / 2; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}
		// 4 -> 3
		for (int i = N / 2, k = N / 2; i < N && k < N; i++, k++) {
			for (int j = 0, l = M / 2; j < M / 2 && l < M; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}
		// 3 -> 2
		for (int i = N / 2, k = 0; i < N && k < N / 2; i++, k++) {
			for (int j = M/2, l = M / 2; j < M && l < M; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}

		// 2 -> 1
		for (int i = 0, k = 0; i < N /2 && k < N / 2; i++, k++) {
			for (int j = M / 2, l = 0; j < M && l < M / 2; j++, l++) {
				copied[k][l] = arr[i][j];
			}
		}

		return copied;
	}

}