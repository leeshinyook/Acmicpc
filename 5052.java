
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        boolean flag = false;
        for(int i = 0; i < T; i++) {
            int count = Integer.parseInt(br.readLine());
            String[] arr = new String[count];
            for(int j = 0; j < count; j++) {
                String str = br.readLine();
                arr[j] = str;
            }
            Arrays.sort(arr);

            for(int j = 0; j < count - 1; j++) {
                if(arr[j + 1].indexOf(arr[j]) == 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
                flag = false;
            }

        }
    }
}
