import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static String[] arr;
    static boolean[] visited;
    static int l,c;

    public static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = br.readLine().split(" ");
    }

    public static boolean isVowel(String s) {
        return s.equals("a") || s.equals("e") || s.equals("i") ||
                s.equals("o") || s.equals("u");
    }

    public static void process(int count, int start) {
        if(count==l) {
            int vowel = 0;
            for(int i=0; i<visited.length; i++) {
                if(visited[i]) {
                    if(isVowel(arr[i])) {
                        ++vowel;
                    }
                }
            }
            if(vowel<1 || (l-vowel)<2) {
                return;
            } else {
                for(int i=0; i<visited.length; i++) {
                    if(visited[i]) {
                        sb.append(arr[i]);
                    }
                }
                sb.append("\n");
            }
            return;
        }

        for(int i=start; i<visited.length; i++) {
            if(visited[i]) {
                continue;
            }
            visited[i] = true;
            process(count+1,i+1);
            visited[i] = false;
        }
    }

    public static void solve() {
        Arrays.sort(arr);
        visited = new boolean[c];
        process(0,0);
        System.out.print(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }
}
