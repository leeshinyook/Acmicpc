import java.io.*;
import java.util.StringTokenizer;
public class Main {
    public static long how_many(long t, long d) {
        long ret = 0; long dt = d;
        while(t >= dt) {
            ret += (t / dt); dt *= d;
        }
        return ret;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        long n, m;
        long d5 = 5, d2 = 2;
        long num_5, num_2;
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        // n의 5의 개수와 2의 개수
        num_5 = how_many(n, d5); num_2 = how_many(n, d2);
        // m의 5의 개수와 2의 개수
        num_5 -= how_many(m, d5); num_2 -= how_many(m, d2);
        // n-m의 5의 개수와 2의 개수
        num_5 -= how_many(n-m, d5); num_2 -= how_many(n-m, d2);
        System.out.println(num_5 > num_2 ? num_2:num_5);
        return;
    }
}

