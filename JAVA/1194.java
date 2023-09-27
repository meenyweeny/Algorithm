import java.io.*;
import java.util.*;

public class JUN1194_이경민 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	static class Pair<A,B> {
		A x;
		B y;
		public Pair(A x, B y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static final char empty = '.';
	static final char exit = '1';
	static final char wall = '#';
	
	static int n,m;
	static char[][] map;
	static Pair<Integer,Integer> start;
	static boolean visited[][][];
	
	public static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new char[n][m];
		visited = new boolean[n][m][64];
		for(int i=0; i<n; i++) {
			String s = br.readLine();
			for(int j=0; j<m; j++) {
				map[i][j] = s.charAt(j);
				if(map[i][j]=='0') {
					start = new Pair(i,j);
				}
			}
		}
	}
	
	public static boolean checkRange(int x, int y) {
		return x>=0 && y>=0 && x<n && y<m;
	}
	
	public static boolean isKey(int x,int y) {
		return map[x][y] >= 'a' && map[x][y] <= 'f';
	}
	
	public static boolean isDoor(int x,int y) {
		return map[x][y] >= 'A' && map[x][y] <= 'F';
	}
	
	public static int solution() {
		ArrayDeque<Pair<Pair<Integer,Integer>,Pair<Integer,Integer>>> q = new ArrayDeque<>();
		q.add(new Pair(new Pair(start.x, start.y),new Pair(0,0)));
		visited[start.x][start.y][0] = true;
		while(!q.isEmpty()) {
			int fx = q.getFirst().x.x;
			int fy = q.getFirst().x.y;
			int count = q.getFirst().y.x;
			int key = q.poll().y.y;
			if(map[fx][fy]==exit) {
				return count;
			}
			for(int i=0; i<4; i++) {
				int nx = fx + "2011".charAt(i) - '1';
				int ny = fy + "1120".charAt(i) - '1';
				int newKey = key;
				if(!checkRange(nx, ny)) {
					continue;
				}
				if(map[nx][ny]==wall) {
					continue;
				}
				if(visited[nx][ny][key]) {
					continue;
				}
				if(isDoor(nx, ny)) {
					int doorIndex = map[nx][ny] - 'A';
					doorIndex = (1<<doorIndex) & key;
					if(doorIndex==0) {
						continue;
					}
				}
				if(isKey(nx, ny)) {
					newKey |= (1<<(map[nx][ny]-'a'));
				}
				visited[nx][ny][newKey] = true;
				q.addLast(new Pair(new Pair(nx,ny),new Pair(count+1,newKey)));
			}
		}
		return -1;
	}
	
	public static void main(String[] args) throws Exception {
		input();
		System.out.print(solution());
	}

}
