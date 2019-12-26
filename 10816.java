import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;
// 수 찾기

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int v, M, input;
        HashMap<Integer, Integer> arr = new HashMap<Integer, Integer>(T + 1);
        String[] num = br.readLine().split(" ");
        for(int i = 0; i < T; i++) {
            input = Integer.parseInt(num[i]);
            if(arr.containsKey(input)) {
                v = arr.get(input);
                v++;
                arr.put(input, v);
            } else {
                arr.put(input, 0);
            }
        }
        M = Integer.parseInt(br.readLine());
        num = br.readLine().split(" ");
        for(int i = 0; i < M; i++) {
            input = Integer.parseInt(num[i]);
            if(arr.containsKey(input)) {
                System.out.print(arr.get(input) + 1 + " ");
            } else {
                System.out.print(0 + " ");
            }
        }
    }

}