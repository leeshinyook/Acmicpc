import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {


    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        int max = 0;
        HashMap<String, Integer> map = new LinkedHashMap<>();
        ArrayList ans = new ArrayList();
        for(int i = 0; i < M; i++) {
            String str = br.readLine();
            if(map.containsKey(str)) {
                int num = map.get(str);
                map.put(str, ++num);
            } else {
                map.put(str, 1);
            }
        }
        for(Integer value : map.values()) {
            if(max < value) {
                max = value;
            }
        }
        for(String Key : map.keySet()) {
            if(map.get(Key) == max) {
                ans.add(Key);
            }
        }
        Collections.sort(ans);
        System.out.println(ans.get(0));





    }
}
