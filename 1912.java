import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int max = 0, sum = 0;
        int[] dp = new int[T + 1];
        int[] arr = new int[T + 1];
        for(int i = 0; i < T; i++) {
            arr[i] = sc.nextInt();
        }
        dp[0] = arr[0];
        max = arr[0];
        for(int i = 1; i < T; i++) {
            dp[i] = Math.max(dp[i - 1] + arr[i], arr[i]);
            max = Math.max(dp[i], max);
        }
        System.out.println(max);
    }
}
