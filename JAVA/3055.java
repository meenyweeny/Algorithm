import java.io.*;
import java.util.*;

public class JUN3055_이경민 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static class Pair<A,B> {
        A x;
        B y;
        Pair(A x,B y) {
            this.x = x;
            this.y = y;
        }
    }

    static final String kaktus = "KAKTUS";
    static final char stone = 'X';
    static final char water = '*';
    static final char empty = '.';
    static final char exit = 'D';

    static int r,c;
    static char[][] map;
    static boolean[][] visited;
    static Pair<Integer,Integer> start;
    static ArrayList<Pair<Integer,Integer>> waters = new ArrayList<>();

    public static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        visited = new boolean[r][c];
        map = new char[r][c];
        for(int i=0; i<r; i++) {
            String str = br.readLine();
            for(int j=0; j<c; j++) {
                map[i][j] = str.charAt(j);
                if(map[i][j]=='S') {
                    map[i][j] = empty;
                    start = new Pair(i,j);
                } else if(map[i][j]==water) {
                    waters.add(new Pair(i,j));
                }
            }
        }
    }

    public static boolean checkRange(int x,int y) {
        return x>=0 && y>=0 && x<r && y<c;
    }

    public static void spreadWater() {
        int size = waters.size();
        for(int k=0; k<size; k++) {
            Pair<Integer,Integer> w = waters.get(k);
            for(int i=0; i<4; i++) {
                int nx = w.x + "2011".charAt(i) - '1';
                int ny = w.y + "1120".charAt(i) - '1';
                if(!checkRange(nx,ny)) {
                    continue;
                }
                char ch = map[nx][ny];
                if(ch==water||ch==stone||ch==exit) {
                    continue;
                }
                map[nx][ny] = water;
                waters.add(new Pair(nx,ny));
            }
        }
    }

    public static String solve() {
        ArrayDeque<Pair<Pair<Integer,Integer>,Integer>> q = new ArrayDeque<>();
        visited[start.x][start.y] = true;
        q.add(new Pair(start,0));
        int before = -1;
        while(!q.isEmpty()) {
            int fx = q.getFirst().x.x;
            int fy = q.getFirst().x.y;
            int count = q.pollFirst().y;
            if(map[fx][fy]==exit) {
                return Integer.toString(count);
            }
            if(before!=count) {
                before=count;
                spreadWater();
            }
            ++count;
            for(int i=0; i<4; i++) {
                int nx = fx + "2011".charAt(i) - '1';
                int ny = fy + "1120".charAt(i) - '1';
                if(!checkRange(nx,ny)) {
                    continue;
                }
                if(visited[nx][ny]) {
                    continue;
                }
                char ch = map[nx][ny];
                if(ch==water || ch==stone) {
                    continue;
                }
                visited[nx][ny] = true;
                q.addLast(new Pair(new Pair(nx,ny),count));
            }
        }
        return kaktus;
    }

    public static void main(String[] args) throws Exception {
        input();
        System.out.print(solve());
    }
}
