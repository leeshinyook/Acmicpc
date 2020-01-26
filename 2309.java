import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[9];
        ArrayList<Integer> ans = new ArrayList<>(7);
        int sum = 0;
        int[] idx = new int[2];
        for(int i = 0; i < 9; i++) {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (i != j) {
                    if(100 == sum - arr[i] - arr[j]){
                        idx[0] = i;
                        idx[1] = j;
                        i = 10;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < 9; i++) {
            if( i != idx[0] && i != idx[1]) {
                ans.add(arr[i]);
            }
        }
        Collections.sort(ans);
        for(Integer e : ans) {
            System.out.println(e);
        }
    }
}
