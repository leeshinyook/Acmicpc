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
        String[] input = br.readLine().split(" ");
        String str = input[0];
        String target_str = input[1];
        int min = 100, count = 0;
        for(int i = 0; i <= target_str.length() - str.length(); i++) {
            for(int j = 0; j < str.length(); j++) {
                if(str.charAt(j) != target_str.charAt(i + j)) {
                    count++;
                }
            }
            if(min > count) min = count;
            count = 0;
        }
        System.out.println(min);
    }
}
