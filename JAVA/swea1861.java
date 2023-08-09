import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *     이동 가능한 좌표 중 가장 값이 작은 것 판단?
 * 2. strategy: 풀이전략
 *     좌표의 값이 작은 것 부터 탐색
 * 3. note: 주의할 사항(특이사항)
 */

public class Main {
	
	static class Point implements Comparable<Point>{
		int x,y,count;
		public Point(int i, int j, int k) {
			x = i; y = j; count = k;
		}
		@Override
		public int compareTo(Main.Point o) {
			return count - o.count;
		}
	}
	
	static int n;
	static int[][] map = new int[500][500];
	static boolean[][] visited = new boolean[500][500];
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,-1,1};
	static PriorityQueue<Point> pq = new PriorityQueue<Point>();
	
	public static void init() {
		for(int i=0; i<500; i++) for(int j=0; j<500; j++) {
			map[i][j]=0;
			visited[i][j] = false;
		}
	}
	
	public static boolean isInRange(int x,int y) {
		return x>=0 && y>=0 && x<n && y<n;
	}
	
	public static Point bfs(int x,int y) {
		int count = 1;
		Queue<Point> q = new ArrayDeque<Point>();
		q.add(new Point(x,y,1));
		
		while(!q.isEmpty()) {
			Point f = q.poll();
			visited[f.x][f.y] = true;
			for(int i=0; i<4; i++) {
				int nx = f.x + dx[i];
				int ny = f.y + dy[i];
				
				if(!isInRange(nx,ny)) {
					continue;
				}
				if(visited[nx][ny]) {
					continue;
				}
				if(map[f.x][f.y]+1 != map[nx][ny]) {
					continue;
				}
				
				q.add(new Point(nx,ny,f.count+1));
				count = Math.max(count, f.count+1);
			}
		}
		return new Point(x,y,count);
	}
	
	public static Point getPoint(Point a,Point b) {
		if(a.count == b.count) {
			return map[a.x][a.y] > map[b.x][b.y] ? b : a;
		} else {
			return a.count < b.count ? b : a;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; tc++) {
			n = Integer.parseInt(br.readLine());
			
			for(int i=0; i<n; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					pq.add(new Point(i,j,map[i][j]));
				}
			}
			
			Point answer = new Point((int)0,(int)0,(int)-1);
			Point front;
			while(!pq.isEmpty()) {
				front = pq.poll();
				if(!visited[front.x][front.y]) {
					answer = getPoint(answer,bfs(front.x,front.y));
				}
			}
			sb.append("#"+tc+" "+map[answer.x][answer.y]+" "+answer.count+"\n");
			
			init();
		}
		System.out.print(sb);
	}
}
