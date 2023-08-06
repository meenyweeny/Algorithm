import java.io.*;
import java.util.*;

public class Main {

    static String str;
    static Deque<Character> lhs = new ArrayDeque<Character>();
    static Deque<Character> rhs = new ArrayDeque<Character>();

    public static void build() {
        int length = str.length();
        for(int i=0; i<length; i++) {
            lhs.addLast(str.charAt(i));
        }
    }

    public static void print() {
        StringBuilder sb = new StringBuilder();
        for (Character l:lhs) {
            sb.append(l);
        }
        for (Character r:rhs) {
            sb.append(r);
        }
        System.out.print(sb);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        str = br.readLine();
        int t = Integer.parseInt(br.readLine());
        build();
        for(int i=0; i<t; i++) {
            st = new StringTokenizer(br.readLine());
            char cmd = st.nextToken().charAt(0);
            if(cmd=='P') {
                lhs.addLast(st.nextToken().charAt(0));
            } else if(cmd=='D') {
                if(rhs.isEmpty()) {
                    continue;
                }
                lhs.addLast(rhs.pollFirst());
            } else if(cmd=='L') {
                if(lhs.isEmpty()) {
                    continue;
                }
                rhs.addFirst(lhs.pollLast());
            } else {
                if(lhs.isEmpty()) {
                    continue;
                }
                lhs.removeLast();
            }
        }
        print();
    }
}
