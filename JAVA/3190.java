import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static class Pair {
        int x; int y;
        Pair(int x, int y) {
            this.x = x; this.y = y;
        }
    }

    static final int size = (int)1e3 + 1;
    static final char snake = 's';
    static final char apple = 'a';
    static final char empty = 'e';
    static int n,k,l;
    static char[][] map = new char[size][size];
    static ArrayDeque<Pair> body = new ArrayDeque<>();
    static Queue<Pair> command = new ArrayDeque<>();
    static int dir = 0;
    static int[] dx = {0,1,0,-1};
    static int[] dy = {1,0,-1,0};
    static Pair now = new Pair(1,1);

    public static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        int a,b;
        for(int i=0; i<k; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            map[a][b] = apple;
        }

        map[1][1] = snake;
        body.addLast(new Pair(1,1));

        l = Integer.parseInt(br.readLine());
        while(--l>=0) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = (st.nextToken().charAt(0) == 'D') ? 1 : -1;
            command.add(new Pair(a,b));
        }
    }

    public static boolean checkRange(int x,int y) {
        return x>0 && y>0 && x<=n && y<=n;
    }

    public static void convertDirection(int newDir) {
        if(newDir==1) {
            dir = (dir+1)%4;
        } else {
            dir = (dir==0) ? 3 : dir-1;
        }
    }

    public static boolean go() {
        int nx = now.x + dx[dir];
        int ny = now.y + dy[dir];
        if(!checkRange(nx,ny)) {
            return false;
        }
        if(map[nx][ny]==snake) {
            return false;
        } else if(map[nx][ny]==apple) {
            map[nx][ny] = snake;
            body.addFirst(new Pair(nx,ny));
        } else {
            map[nx][ny] = snake;
            body.addFirst(new Pair(nx,ny));
            map[body.peekLast().x][body.pollLast().y] = empty;
        }
        now.x = nx;
        now.y = ny;
        return true;
    }

    public static int run() {
        int second = 0;
        while(true) {
            if(!go()) {
                ++second;
                break;
            }
            ++second;
            if(!command.isEmpty()) {
                if(command.peek().x == second) {
                    convertDirection(command.poll().y);
                }
            }
        }
        return second;
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(run());
    }
}
