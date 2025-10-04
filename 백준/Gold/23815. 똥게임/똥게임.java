import java.io.*;
import java.util.*;

/**
 *packageName    : _251004
 * fileName       : BOJ_G4_23815_똥게임
 * author         : moongi
 * date           : 10/4/25
 * description    :
 *
 * 두 가지 선택지 중 하나를 선택해야 한다.
 * 두 개의 선택지는 동일할 수 있다.
 * 한 번에 한해 선택지를 건너뛸 수 있다. -> 굳이 안 건너뛰어됨.
 * 해당 턴이 끝나고 사람이 0명 이하가 되면 게임이 종료가 된다.
 *
 * 문제에서는 모든 턴이 끝난 뒤, 사람의 수를 최대로 만들고 싶다.
 *
 */
public class Main {

	static class Choice {
		char mod;
		int count;

		public Choice(char mod, int count) {
			this.mod = mod;
			this.count = count;
		}
	}
	
	static final int DEAD = -1;

	static Choice[][] choices;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		choices = new Choice[N+1][2];

		for (int i = 0; i < N; i++) {

			String[] str = br.readLine().split(" ");

			char mod = str[0].charAt(0);
			int count = Integer.parseInt(str[0].substring(1));

			choices[i + 1][0] = new Choice(mod, count);

			mod = str[1].charAt(0);
			count = Integer.parseInt(str[1].substring(1));

			choices[i + 1][1] = new Choice(mod, count);


		}

		int[][] dp = new int[N + 1][2];
		
		for (int i = 0; i <= N; i++) {
			Arrays.fill(dp[i], DEAD);
		}
		
		dp[0][0] = 1;
		dp[0][1] = 0;

		for (int i = 1; i <= N; i++) {

			int a = playGame(choices[i][0].mod, choices[i][0].count, dp[i - 1][0]);
			int b = playGame(choices[i][1].mod, choices[i][1].count, dp[i - 1][0]);

			int c = playGame(choices[i][0].mod, choices[i][0].count, dp[i - 1][1]);
			int d = playGame(choices[i][1].mod, choices[i][1].count, dp[i - 1][1]);

			dp[i][0] = Math.max(a, b);
			dp[i][1] = Math.max(Math.max(c, d), dp[i - 1][0]);

		}

		int ans = Math.max(dp[N][0], dp[N][1]);

		if (ans == DEAD) {
			System.out.println("ddong game");
		} else {
			System.out.println(ans);
		}
	}

	static int playGame(char mod, int change, int people) {
		if (people <= 0) return DEAD;
		
		int res;
		if (mod == '*') res = people * change;
		else if (mod == '-') res = people - change;
		else if (mod == '+') res = people + change;
		else res = people / change;

		return res <= 0 ? DEAD : res;

	}
}