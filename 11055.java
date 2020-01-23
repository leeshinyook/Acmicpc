
import java.io.BufferedReader;
        import java.io.IOException;
        import java.io.InputStreamReader;
        import java.lang.reflect.Array;
        import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] num = new int[T];
        int[] dp = new int[T];
        for(int i = 0; i < T; i++) {
            num[i] = sc.nextInt();
        }
        int max = dp[0] = num[0];
        for(int i = 1; i < T; i++) {
            dp[i] = num[i];
            for(int j = 0; j < i; j++) {
                if(num[j] < num[i] && dp[i] < dp[j] + num[i]) {
                    dp[i] = dp[j] + num[i];
                }
            }
            if(max < dp[i]) max = dp[i];
        }
        System.out.println(max);

    }
}
