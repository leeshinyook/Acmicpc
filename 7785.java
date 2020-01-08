import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, String> list = new HashMap<String, String>();
        ArrayList<String> ans = new ArrayList<String>();
        int M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
            String[] input = br.readLine().split(" ");
            String name = input[0];
            String status = input[1];
            list.put(name, status);
        }
        list.forEach((key, value) -> {
            if(value.equals("enter")) {
                ans.add(key);
            }
        });
       Collections.sort(ans);
       int length = ans.size() - 1;
       for(int i = length; i >= 0; i--) {
           System.out.println(ans.get(i));
       }

    }

}