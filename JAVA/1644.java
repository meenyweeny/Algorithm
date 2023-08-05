import java.io.*;
import java.util.*;

public class Main {

    static final int sz = (int)4e6 + 1;
    static boolean[] prime = new boolean[sz];
    static int answer,n;
    static ArrayList<Integer> list = new ArrayList<Integer>();

    public static void makeBoard() {
        prime[1] = true;
        int sqrt = (int)Math.sqrt(sz);
        for(int i=2; i<=sqrt; i++) {
            for(int j=i+i; j<sz; j+=i) {
                prime[j] = true;
            }
        }
        for(int i=1; i<=n; i++) {
            if(prime[i]) {
                continue;
            }
            list.add(i);
        }
    }

    public static void solution() {
        if(list.size()==0) {
            System.out.println(0);
            return;
        }
        int start = 0;
        int end = 0;
        int sum = list.get(0);
        while(start<list.size() && end<list.size()) {
            if(sum==n) {
                ++answer;
                ++end;
                if(end==list.size()) {
                    continue;
                }
                sum += list.get(end);
            } else if(sum<n) {
                ++end;
                if(end==list.size()) {
                    continue;
                }
                sum += list.get(end);
            } else if(sum>n) {
                sum -= list.get(start);
                ++start;
            }
        }

        System.out.println(answer);
    }

    public static void solve() {
        makeBoard();
        solution();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        solve();
    }
}
