import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;
// 수 찾기

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        HashMap<Integer, Integer> HashMap = new HashMap<Integer, Integer>(N);
        for(int i = 0; i < N; i++) {
            HashMap.put(Integer.parseInt(str[i]), 0);
        }
        int M = Integer.parseInt(br.readLine());
        String[] str2 = br.readLine().split(" ");
        for(int i = 0; i < M; i++) {
            if(HashMap.containsKey(Integer.parseInt(str2[i]))){
                System.out.print(1 + " ");
            } else {
                System.out.print(0 + " ");
            }
        }

    }


}
