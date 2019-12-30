import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long[] dp = new long[100];
        int T = sc.nextInt();
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i < 100; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        while(T-- > 0) {
            int num = sc.nextInt();
            System.out.println(dp[num]);
        }
    }
}
