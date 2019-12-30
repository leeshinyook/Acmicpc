import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        long[] dp = new long[100];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 2;
        for(int i = 5; i < 100; i++) {
            dp[i] = dp[i - 5] + dp[i - 1];
        }
        while(T-- > 0) {
            int num = sc.nextInt();
            System.out.println(dp[num - 1]);
        }
    }
}
