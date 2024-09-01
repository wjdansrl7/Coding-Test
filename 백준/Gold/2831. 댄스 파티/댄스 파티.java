import java.util.*;
import java.io.*;

public class Main {
    static int N;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pm = new PriorityQueue<>();
        PriorityQueue<Integer> mm = new PriorityQueue<>();
        PriorityQueue<Integer> pw = new PriorityQueue<>();
        PriorityQueue<Integer> mw = new PriorityQueue<>();


        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(st.nextToken());

            if (x > 0) pm.add(x);
            else mm.add(-x);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(st.nextToken());

            if (x > 0) pw.add(x);
            else mw.add(-x);
        }

        int res = 0;
        while (!mm.isEmpty() && !pw.isEmpty()) {
            int m = mm.poll();
            int w = 2501;
            w = pw.peek();

            if (w < m) {
                res++;
                pw.poll();
            }
        }
        while (!pm.isEmpty() && !mw.isEmpty()) {
            int w = mw.poll();
            int m = pm.peek();

            if (m < w) {
                res++;
                pm.poll();
            }
        }

        System.out.println(res);
    }
}