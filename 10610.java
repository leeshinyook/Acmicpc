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
        String[] input = br.readLine().split("");
        int sum = 0;
        boolean zeroChecker = false;
        for(int i = 0; i < input.length; i++) {
            if(Integer.parseInt(input[i]) == 0) {
                zeroChecker = true;
            }
            sum += Integer.parseInt(input[i]);
        }
        if(sum % 3 == 0 && zeroChecker) {
            Arrays.sort(input, Comparator.reverseOrder());
        } else {
            System.out.println(-1);
            return;
        }
        for(int i = 0; i < input.length; i++) {
            System.out.print(input[i]);
        }
    }
}
