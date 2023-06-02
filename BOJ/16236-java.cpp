import java.io.*;
import java.util.*;

class Shark {
    int x,y;

    Shark(int xx,int yy) {
        x=xx; y=yy;
    }
}

class Fish {
    int dist,x,y;
    Fish(int d,int xx,int yy) {
        dist=d; x=xx; y=yy;
    }
}

public class Main {

    static int map[][];
    static int n;
    static int shark_size = 2;
    static int shark_eat = 0;
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,-1,1};
    static Shark shark;
    static int answer = 0;
    static ArrayList<Fish> fish = new ArrayList<>();

    static boolean is_in_range(int x,int y) {
        return x>=1 && y>=1 && x<=n && y<=n;
    }

    static void bfs() {
        fish.clear();
        boolean visited[][] = new boolean[n+1][n+1];
        Queue<Fish> q = new LinkedList<>();
        q.add(new Fish(0,shark.x, shark.y));
        visited[shark.x][shark.y] = true;
        Fish front = new Fish(0,0,0);

        while(!q.isEmpty()) {
            front = q.poll();

            for(int i=0; i<4; i++) {
                int nx = front.x + dx[i];
                int ny = front.y + dy[i];
                int count = front.dist;

                if(!is_in_range(nx,ny)) {
                    continue;
                }
                if(visited[nx][ny]) {
                    continue;
                }
                if(map[nx][ny]>shark_size) {
                    continue;
                }

                visited[nx][ny] = true;
                q.add(new Fish(count+1,nx,ny));
                if(map[nx][ny]<shark_size && map[nx][ny]!=0) {
                    fish.add(new Fish(count+1,nx,ny));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        map = new int[n +1][n +1];
        shark = new Shark(0,0);
        shark_size = 2;

        Comparator<Fish> comp = new Comparator<Fish>() {
            @Override
            public int compare(Fish a, Fish b) {
                if(a.dist==b.dist) {
                    if(a.x==b.x) {
                        return Integer.compare(a.y,b.y);
                    } else {
                        return Integer.compare(a.x,b.x);
                    }
                } else {
                    return Integer.compare(a.dist,b.dist);
                }
            }
        };

        for(int i=1; i<=n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j]==9) {
                    shark.x = i;
                    shark.y = j;
                }
            }
        }

        while(true) {
            bfs();
            if(fish.isEmpty()) {
                break;
            }
            fish.sort(comp);
            Fish f = fish.get(0);
            map[f.x][f.y] = 0;
            answer += f.dist;
            ++shark_eat;
            map[shark.x][shark.y]=0;
            shark.x = f.x;
            shark.y = f.y;
            map[f.x][f.y] = 9;
            if(shark_eat==shark_size) {
                ++shark_size;
                shark_eat = 0;
            }
        }

        StringBuilder sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb.append(answer);
        bw.write(sb.toString());
        bw.flush();
    }
}
