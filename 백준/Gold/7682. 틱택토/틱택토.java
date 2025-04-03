import java.util.*;
import java.io.*;

public class Main {
	static char[][] board;
	static int xCnt, oCnt;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		board = new char[3][3];

		while (true) {

			String str = br.readLine();

			if (str.equals("end")) break;

			xCnt = 0;
			oCnt = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					board[i][j] = str.charAt(i * 3 + j);

					if (board[i][j] == 'X') xCnt++;
					else if (board[i][j] == 'O') oCnt++;
				}
			}

			// 보드판을 다 채운 경우
			if (xCnt + oCnt == 9 && xCnt == oCnt + 1) {

				// 둘이 동시에 이기는 경우는 불가능
				if (check('X') && check('O')) sb.append("invalid").append('\n');
				// 두 번째 사람이 이기는 것은 불가능
				else if (check('O')) sb.append("invalid").append('\n');
				// 이외의 경우
				else sb.append("valid").append('\n');
			} else {
				// 다 채우지 못한 경우
				if (check('X') && check('O')) sb.append("invalid").append('\n');
				else if (check('X') && xCnt == oCnt + 1) sb.append("valid").append('\n');
				else if (check('O') && xCnt == oCnt) sb.append("valid").append('\n');
				else sb.append("invalid").append('\n');
			}
		}
		System.out.println(sb);
	}

	static boolean check(char c) {

		// 가로
		for (int i = 0; i < 3; i++) {
			int cnt = 0;
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == c) cnt++;
 			}
			if (cnt == 3) return true;
		}
		// 세로
		for (int i = 0; i < 3; i++) {
			int cnt = 0;
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == c) cnt++;
			}
			if (cnt == 3) return true;
		}

		// 대각선
		if (board[0][0] == c && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) return true;
		if (board[0][2] == c && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) return true;

		return false;
	}
}