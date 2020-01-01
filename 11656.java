import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        ArrayList<String> arr = new ArrayList<String>();
        for(int i = 0; i < str.length(); i++) {
            String substr = str;
            arr.add(substr.substring(i, str.length()));
        }
        Collections.sort(arr);
        for(int i = 0; i < arr.size(); i++) {
            System.out.println(arr.get(i));
        }
    }
}
