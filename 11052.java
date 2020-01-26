import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] arr = new int[T + 1];
        int[] dp = new int[T + 1];

        for(int i = 1; i <= T; i++) {
            arr[i] = sc.nextInt();
        }

        for(int i = 1; i <= T; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] = Math.max(dp[i], dp[i - j] + arr[j]);
            }
        }

        System.out.println(dp[T]);

    }
}
