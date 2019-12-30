import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int N = sc.nextInt();
        ArrayList num = new ArrayList(T);
        ArrayList ans = new ArrayList(T);
        int idx = N, temp = N;

        for(int i = 0; i < T; i++) {
            num.add(i+1);
        }
        while(num.size() > 0) {
            while(idx > num.size()) {
                idx -= num.size();
            }
            idx = Math.abs(idx);
            ans.add(num.get(idx - 1));
            num.remove(idx - 1);
            idx += temp - 1;

        }
        System.out.print("<");
        for(int i = 0; i < ans.size() - 1; i++) {
            System.out.print(ans.get(i)+", ");
        }
        System.out.print(ans.get(ans.size() - 1) +  ">");

    }
}
