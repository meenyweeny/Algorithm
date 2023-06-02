import java.io.*;
import java.util.*;

class Point {
    int x,y;

    Point(int xx,int yy) {
        x=xx;
        y=yy;
    }
}

class Entry {
    int x,y,count;

    Entry(int xx,int yy,int c) {
        x=xx; y=yy; count=c;
    }
}

public class Main {
    static int m,n;
    static int map[][];
    static boolean visited[][];
    static Queue<Entry> q;
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,-1,1};
    static int answer = 0;

    private static boolean is_in_range(int x,int y) {
        return x>=1 && y>=1 && x<=n && y<=m;
    }

    private static int bfs() {
        int day = 0;
        while(!q.isEmpty()) {
            Entry front = q.poll();
            int count = front.count;

            for(int i=0; i<4; i++) {
                int nx = front.x + dx[i];
                int ny = front.y + dy[i];

                if(!is_in_range(nx,ny)) {
                    continue;
                }
                if(map[nx][ny]==-1 || visited[nx][ny]) {
                    continue;
                }
                q.add(new Entry(nx,ny,count+1));
                visited[nx][ny] = true;
                map[nx][ny] = 1;
                day = day < count+1 ? count+1 : day;
            }
        }
        return day;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        map = new int[n+1][m+1];
        visited = new boolean[n+1][m+1];
        q = new LinkedList<>();
        for(int i=1; i<=n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==1) {
                    q.add(new Entry(i,j,0));
                    visited[i][j] = true;
                }
            }
        }

        answer=bfs();

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(map[i][j]==0) {
                    answer = -1;
                    break;
                }
            }
        }

        System.out.println(answer);
    }
}
