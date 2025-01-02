import java.io.*;
import java.util.*;
/**
 * packageName    : _250102
 * fileName       : BOJ_B1_2851_슈퍼마리오
 * author         : moongi
 * date           : 1/2/25
 * description    :
 */
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int sum = 0, tmp = 0;
        for (int i = 0; i < 10; i++) {
            tmp = Integer.parseInt(br.readLine());
            sum += tmp;
            if (sum > 100) {
                int a = Math.abs(sum - 100);
                int b = Math.abs(sum - tmp - 100);

                if (a <= b) System.out.println(sum);
                else System.out.println(sum - tmp);
                return;
            }
        }
        System.out.println(sum);
    }
}