
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int seq = 1, count = 1;
        String str =  sc.nextLine();
        char temp = str.charAt(0);
        char fix = str.charAt(0);
        for(int i = 0; i < str.length(); i++) {
            if(temp == str.charAt(i)) {
            } else {
                temp = str.charAt(i);
                if(temp == fix) count++;
                seq++;
            }

        }
        if(seq - count < count) {
            System.out.println(seq - count);
        } else {
            System.out.println(count);
        }
    }
}
