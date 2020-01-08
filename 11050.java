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
        int n = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(binoCoef(n, k));
    }
    public static int binoCoef(int n, int k) {
        if(k == 0 || n == k) return 1;
        return binoCoef(n - 1, k) + binoCoef(n - 1, k - 1);
    }
}