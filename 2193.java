import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        long[] dp  = new long[T + 1];

        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < T + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        System.out.println(dp[T - 1]);
    }
}

