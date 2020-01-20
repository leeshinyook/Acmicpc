
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, Integer> map = new LinkedHashMap<>();
        String[] word = br.readLine().split("");
        String anw = "";
        String odd_key = "";
        int odd = 0;
        Arrays.sort(word);
        for(int i = 0; i < word.length; i++ ) {
            if(map.containsKey(word[i])) {
                int v = map.get(word[i]);
                map.put(word[i], ++v);
            } else {
                map.put(word[i], 1);
            }
        }
        for(Integer value: map.values()) {
            if(value % 2 != 0) {
                odd++;
            }
            if(odd > 1) {
                System.out.println("I'm Sorry Hansoo");
                return;
            }

        }
        for(String key: map.keySet()) {
            int count = map.get(key) / 2;
            for(int i = 0; i < count; i++) {
                anw += key;
            }
            if(map.get(key) % 2 != 0) {
                odd_key += key;
            }
        }
        System.out.print(anw + odd_key + reverseString(anw));
    }
    public static String reverseString(String s) {
        return (new StringBuffer(s)).reverse().toString();
    }
}
