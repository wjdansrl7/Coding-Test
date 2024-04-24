import java.util.*;
import java.io.*;

public class Main {
    static String T, P;
    static int[] pi;
    static int cnt = 0;
    static List<Integer> li;

    static int[] getPi(String p) {

        int pLen = p.length();
        for (int i = 1, j = 0; i < pLen; i++) {
            while (j > 0 && p.charAt(i) != p.charAt(j)) j = pi[j - 1];
            if (p.charAt(i) == p.charAt(j)) pi[i] = ++j;
        }

        return pi;
    }

    static void KMP() {

        int[] pi = getPi(P);

        int tLen = T.length();
        int pLen = P.length();

        for (int i = 0, j = 0; i < tLen; i++) {
            while (j > 0 && T.charAt(i) != P.charAt(j)) j = pi[j - 1];

            if (T.charAt(i) == P.charAt(j)) {
                if (j == pLen - 1) {
                    ++cnt;
                    li.add(i - j + 1);
                    j = pi[j];
                } else j++;
            }
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        T = br.readLine();
        P = br.readLine();

        pi = new int[P.length()];
        li = new ArrayList<>();

        KMP();
        System.out.println(cnt);
        for (int i = 0; i < cnt; i++) {
            System.out.println(li.get(i));
        }
    }
}