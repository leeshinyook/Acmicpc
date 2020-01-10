
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<BigInteger, Integer> map = new HashMap<>();
        ArrayList<BigInteger> ans = new ArrayList<>();
        int max = 0;

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
            String str = br.readLine();
            BigInteger num = new BigInteger(str);
            if(map.containsKey(num)) {
                int existed = map.get(num);
                map.put(num, ++existed);
            } else {
                map.put(num, 1);
            }
        }
        for(Integer value : map.values()) {
            if(max < value) {
                max = value;
            }
        }
        for(BigInteger key : map.keySet()) {
            if(max == map.get(key)) {
                ans.add(key);
            }
        }
        Collections.sort(ans);
        System.out.println(ans.get(0));

    }
}
