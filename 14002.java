import java.io.*;

public class Main {

    static int[] a;
    // 숫자들 저장할 배열
    static int[] v;
    // 역추적에 활용할 배열
    static void go(int p, BufferedWriter bw) throws IOException {
        if (p == -1) {
            return;
        }
        go(v[p], bw);
        bw.write(String.valueOf(a[p]) + " ");
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        a = new int[n];
        v = new int[n];
        // 배열 메모리 할당

        int[] d = new int[n];
        // 증가하는 수열 길이 저장할 배열
        // d[i] = a[1], ~~ a[i] 까지 수열이 있을 때 a[i]를 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이

        String[] words = br.readLine().split(" ");

        for (int i = 0; i < words.length; i++) {
            a[i] = Integer.parseInt(words[i]);
        }
        // words 를 split 해서 숫자를 넣는다

        for (int i = 0; i < n; i++) {
            // 0부터 n까지
            d[i] = 1;
            // 증가하는 수열 길이는 일단 1로 놓고
            v[i] = -1;
            // 역추적 배열은 일단 -1로 놓는다 ( 0부터 시작하니 )
            for (int j = 0; j < i; j++) {
                // 처음부터 i까지 비교하며
                if (a[j] < a[i] && d[i] < d[j] + 1) {
                    // a[i]가 a[j] 보다 크고 d[j] + 1 값이 d[i]보다 길면
                    d[i] = d[j] + 1;
                    // 증가하는 수열 길이를 증가시켜주고
                    v[i] = j;
                    // 역추적하기 위해 배열 인덱스 저장
                }
            }
        }
        int answer = 0;
        int p = 0;
        for (int i = 0; i < d.length; i++) {
            // d 배열에서
            if (answer < d[i]) {
                // 최대값이 바뀌는 순간마다
                answer = d[i];
                // 최대값과 저장하고
                p = i;
            }
        }
        bw.write(String.valueOf(answer) + '\n');
        // 최대값 출력하고
        go(p, bw);
        // 재귀로 출력한다 증가하는 부분 수열 출력
        bw.flush();

    }
}
