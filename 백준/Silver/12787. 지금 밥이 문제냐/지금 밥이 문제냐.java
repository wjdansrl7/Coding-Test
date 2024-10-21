import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    // 해당 target을 이진수로 바꿔준다.
    static String convertBinary(String target) {
        String[] targets = target.split("\\.");
        BigInteger sum = BigInteger.ZERO;
        int s = 56;
        for (int i = 0; i < targets.length; i++) {
            BigInteger tmp = new BigInteger(targets[i]);
            sum = sum.add(tmp.shiftLeft(s));
            s -= 8;
        }
        return sum.toString();
    }

    // 정수를 IPv8 형식으로 변환
    static String convertIPv8(String target) {
        BigInteger t = new BigInteger(target);
        int s = 56;
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < 8; i++) {
            BigInteger[] divmod = t.divideAndRemainder(BigInteger.ONE.shiftLeft(s));
            int v = divmod[0].intValue();  // 몫을 정수로 변환
            t = divmod[1];  // 나머지를 t에 저장
            s -= 8;
            res.append(v);
            if (i != 7) res.append(".");
        }
        return res.toString();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        int M;
        String N;
        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());

            M = Integer.parseInt(st.nextToken());
            N = st.nextToken().trim();
            if (M == 1) {
                // IPv8 -> 정수 변환
                sb.append(convertBinary(N));
            } else {
                // 정수 -> IPv8 주소로 변환
                sb.append(convertIPv8(N));
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}