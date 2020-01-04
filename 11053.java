import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int[] arr = new int[T + 1]; // 인덱스 마다 각 입력값
        int[] dp = new int[T + 1]; // 인덱스마다 각 증가 수열의 길이
        int max = 1;
        dp[0] = 1;
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < T; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        for(int i = 1; i < T; i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
                max = Math.max(dp[i], max);
            }
        }
        System.out.println(max);
    }
}
