import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
    static int n, m;
    static int[] par;
    static String answer;

    static void input() throws IOException {
    	st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    }
    
    static void makeSet() {
    	par = new int[n+1];
    	for(int i=0; i<=n; i++) {
    		par[i] = i;
    	}
    }

    static int find(int x) {
    	if(par[x]==x) {
    		return x;
    	} else {
    		return par[x] = find(par[x]);
    	}
    }
    
    static boolean check(int a,int b) {
    	return find(a) == find(b);
    }
    
    static void merge(int a,int b) {
    	int aRoot = find(a);
    	int bRoot = find(b);
    	
    	if(aRoot==bRoot) {
    		return;
    	} else {
			par[aRoot] = bRoot;
    	}
    }
    
    static void doTask() throws IOException {
    	answer = "";
    	int c,a,b;
    	while(--m>=0) {
    		st = new StringTokenizer(br.readLine());
    		c = Integer.parseInt(st.nextToken());
    		a = Integer.parseInt(st.nextToken());
    		b = Integer.parseInt(st.nextToken());
    		if(c==0) {
    			if(a==b) {
    				continue;
    			}
    			merge(a,b);
    		} else {
    			sb.append(check(a,b) ? 1 : 0);
    		}
    	}
    }
    
    static void solve() throws IOException {
        int t = Integer.parseInt(br.readLine());
        
        for (int tc = 1; tc <= t; tc++) {
            sb.append("#" + tc + " ");
            input();
            makeSet();
            doTask();
            sb.append("\n");
        }
        System.out.print(sb);
    }

    public static void main(String[] args) throws IOException {
        solve();
    }
}
