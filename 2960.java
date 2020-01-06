import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();
        long[] arr = new long[N + 1];
        ArrayList ans = new ArrayList(N + 1);
        for(int i = 2; i < N + 1; i++) {
            arr[i] = i;
        }
        for(int i = 2; i <= N; i++) {
            if(arr[i] == 0) {
                continue;
            }
            ans.add(arr[i]);

            for(int j = i + i; j <= N; j += i) {
                if(arr[j] != 0) {
                    ans.add(arr[j]);
                }
                arr[j] = 0;
            }
        }
        System.out.println(ans.get(K - 1));

    }
}