import java.util.*;
import java.io.*;

/**
 *packageName    : _250504
 * fileName       : BOJ_G4_3078_좋은친구
 * author         : moongi
 * date           : 5/4/25
 * description    :
 * 
 * 해당 문제는 슬라이딩 윈도우인 줄은 알았지만, 접근을 제대로 하지 못했다.
 * nameLen : 들어오는 입력값들의 문자열의 길이를 저장하고,
 * nameLenCnt: 해당 문자열의 길이에 대해 cnt를 해준다.
 * 해당 상태에서 누적합을 통해서 차례대로 K개를 윈도우안에 넣어놓고
 * 윈도우만큼에 대해서 nameLenCnt 값이 있는 것이므로 현재 비교할 대상을 제외하고 해당 길이에 맞는
 * cnt를 추가해준다.
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		int[] nameLen = new int[N+1];
		int[] nameLenCnt = new int[21];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			nameLen[i] = st.nextToken().length();

			// 초기에 K개에 대한 학생수 cnt를 더해준다.
			if (i <= K) {
				nameLenCnt[nameLen[i]]++;
			}
		}

		long res = --nameLenCnt[nameLen[0]];

		for (int i = 1; i < N; i++) {
			if (i + K < N) nameLenCnt[nameLen[i + K]]++;
			res += --nameLenCnt[nameLen[i]];
		}

		System.out.println(res);


	}
}