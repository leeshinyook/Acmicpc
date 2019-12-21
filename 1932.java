import java.lang.Math;
import java.util.Scanner;

//Bottom Up
public class Main {

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] dp = new int[n + 1][n + 1];
        int max = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i][j] = sc.nextInt();
               if(j == 0) dp[i][j] = dp[i - 1][j] + dp[i][j];
               else if(j == i) dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
               else dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];

               if(max < dp[i][j]) max = dp[i][j]; // 최대값 판정
            }
        }
        System.out.println(max);

    }
}
