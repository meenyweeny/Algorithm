import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *     최대 m개의 좌표 중 가장 가까운 거리 계속 구하기
 * 2. strategy: 풀이전략
 *     최대 m개를 고른 순열 구하면서 거리 계속 구해보기
 * 3. note: 주의할 사항(특이사항)
 */

class Point {
	int x;
	int y;
	
	Point(int x,int y) {
		this.x = x; this.y = y;
	}
}

public class Main {
	
	static int n,m;
	static int answer = (int)2e9;
	static int[][] map = new int[50][50];
	static int[][][] dist = new int[50][50][13];
	static ArrayList<Point> store = new ArrayList<Point>();
	static ArrayDeque<Integer> close = new ArrayDeque<Integer>();
	
	public static int getDistance(int x,int y,int xx,int yy) {
		return Math.abs(xx - x) + Math.abs(y - yy);
	}
	
	public static void makeDistance() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(map[i][j]!=1) {
					continue;
				}
				for(int k=0; k<store.size(); k++) {
					dist[i][j][k] = getDistance(i,j,store.get(k).x,store.get(k).y);
				}
			}
		}
	}
	
	public static int getAnswer() {
		int sum = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(map[i][j]!=1) {
					continue;
				}
				int d = (int)2e9;
				for(Integer index:close) {
					d = Math.min(d, dist[i][j][index]);
				}
				sum += d;
			}
		}
		return sum;
	}
	
	public static void peekStore(int count, int start) {
		if(count>m) {
			return;
		}
		if(count!=0) {
			answer = Math.min(answer, getAnswer());
		}
		for(int i=start; i<store.size(); i++) {
			close.addLast(i);
			peekStore(count+1,i+1);
			close.pollLast();
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j]==2) {
					store.add(new Point(i,j));
				}
			}
		}
		
		makeDistance();
		peekStore(0,0);
		System.out.println(answer);
	}
}
