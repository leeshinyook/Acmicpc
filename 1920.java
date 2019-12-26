import java.util.*;
import java.lang.*;
// 수 찾기

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] ans;
        int num, M;
        HashMap<Integer, Integer> arr = new HashMap<Integer, Integer>(T);
        for(int i = 0; i < T; i++) {
            num = sc.nextInt();
            arr.put(num, 0);
        }
        M = sc.nextInt();
        ans = new int[M];
        for(int i = 0; i < M; i++) {
            num = sc.nextInt();
            if(arr.containsKey(num)) {
                ans[i] = 1;
            } else ans[i] = 0;
        }

        for(int i = 0; i < M; i++) {
            System.out.println(ans[i]);
        }




    }

}