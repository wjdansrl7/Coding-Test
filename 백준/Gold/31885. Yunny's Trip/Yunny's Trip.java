import java.util.*;
import java.io.*;

public class Main {
    static final long LINF = 0x3f3f3f3f3f3f3f3fL;
    static final int[] dr = {0, 1, -1, 0, 0}, dc = {0, 0, 0, 1, -1};

    static long N, K;
    static long dx, dy;
    static List<long[]> items = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        K = Long.parseLong(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            items.add(new long[]{x, y});
        }

        st = new StringTokenizer(br.readLine());
        dx = Long.parseLong(st.nextToken());
        dy = Long.parseLong(st.nextToken());

        items.sort((a, b) -> {
            if (a[0] == b[0]) return Long.compare(a[1], b[1]);
            return Long.compare(a[0], b[0]);
        });

        long ans = LINF;

        ans = Math.min(ans, Math.abs(dx) + Math.abs(dy));

        for (long[] item : items)
            ans = Math.min(ans, Math.abs(dx - item[0]) + Math.abs(dy - item[1]) + 2);

        for (long[] item : items) {
            long ix = item[0], iy = item[1];
            for (int k = 0; k < 5; k++) {
                long stamina = (k == 0) ? 4 : 5;
                long tx = ix + dr[k], ty = iy + dc[k];

                // F-T binary search
                int lo = 0, hi = (int) N - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (Check(mid, tx, ty)) hi = mid - 1;
                    else lo = mid + 1;
                }

                if (lo < items.size()) {
                    tx += items.get(lo)[0];
                    ty += items.get(lo)[1];
                }

                if (tx == dx && ty == dy) ans = Math.min(ans, stamina);
            }
        }

        System.out.println(ans > K ? -1 : ans);
    }

    static boolean Check(int mid, long ix, long iy) {
        if (items.get(mid)[0] + ix == dx)
            return items.get(mid)[1] + iy >= dy;
        return items.get(mid)[0] + ix > dx;
    }

}