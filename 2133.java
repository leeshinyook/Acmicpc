import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        long[] dp = new long[T + 1];
        if(T % 2 != 0) {
            System.out.println(0);
            return;
        }
        dp[0] = 1;
        dp[2] = 3;

        for(int i = 4; i <= T + 1; i += 2) {
            dp[i] = dp[i - 2] * 3;
            for(int j = 4; j <= i; j += 2) {
                dp[i] += dp[i - j] * 2;
            }
        }
        System.out.println(dp[T]);
    }
}
