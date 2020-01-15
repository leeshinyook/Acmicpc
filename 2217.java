import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int max = 0, sum = 0;
        Integer[] rope = new Integer[T];
        for(int i = 0; i < T; i++) {
            rope[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(rope, Comparator.reverseOrder());
        for(int i = 0; i < rope.length; i++) {
            if(max < rope[i] * (i + 1)) {
                max = (rope[i] * (i + 1));
            }
        }
        System.out.println(max);
    }
}
