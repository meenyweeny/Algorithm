import java.io.*;
import java.util.*;

public class SW7465_이경민 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int answer = 0;
    static int n,m;
    static ArrayList<Integer>[] graph;
    static boolean[] visited;

    public static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        graph = new ArrayList[n+1];
        for(int i=0; i<=n; i++) {
            graph[i] = new ArrayList<>();
        }
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }
        visited = new boolean[n+1];
    }

    public static void bfs(int x) {
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.push(x);
        visited[x] = true;
        while(!q.isEmpty()) {
            int front = q.pollFirst();

            for(Integer g:graph[front]) {
                if(visited[g]) {
                    continue;
                }
                visited[g] = true;
                q.push(g);
            }
        }
    }

    public static void solve() {
        answer = 0;
        for(int i=1; i<=n; i++) {
            if(visited[i]) {
                continue;
            }
            bfs(i);
            ++answer;
        }
    }

    public static void main(String[] args) throws Exception {
        int t;
        t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; tc++) {
            input();
            solve();
            System.out.println("#"+tc+" "+answer);
        }
    }
}
