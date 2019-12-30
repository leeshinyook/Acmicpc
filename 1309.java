import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] dp = new int[T + 1];
        dp[0] = 1;
        dp[1] = 3;
        for(int i = 2; i <= T; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
        }
        System.out.println(dp[T]);

    }
}
