import java.lang.Math;
import java.lang.reflect.Array;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] dp = new int[T];
        int[] num = new int[T];

        for(int i = 0; i < T; i++) {
            num[i] = sc.nextInt();
        }
        dp[0] = num[0];
        dp[1] = num[0] + num[1];
        dp[2] = Math.max(num[0] + num[2], num[1] + num[2]);

        for(int i = 3; i < T; i++) {
            dp[i] = Math.max(dp[i - 3] + num[i] + num[i - 1], dp[i - 2] + num[i]);

        }
        System.out.println(dp[T - 1]);
    }
}
