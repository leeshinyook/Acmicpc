import java.util.*;
import java.lang.*;
// 수 찾기

public class Main {
    static int[] arr = new int[100001];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m, temp;
        n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr, 0, n);
        m = sc.nextInt();

        for(int i = 0; i < m; i++) {
            temp = sc.nextInt();
            BinarySearch(n, temp);
        }
    }
    public static void BinarySearch(int n, int key) {
        int start = 0;
        int end = n - 1;
        int mid;
        while(end - start >= 0) {
            mid = (start + end) / 2;
            if(arr[mid] == key) { // 키 값이 중앙값과 같을때
                System.out.println(1);
                return;
            } else if(arr[mid] > key) { // 키값이 중앙값보다 작을때
                end = mid - 1;
            } else  { // 키값이 중앙값보다 클떄
                start = mid + 1;
            }
        }
        System.out.println(0);
        return;
    }

}