import java.io.*;
import java.util.*;

public class Main {

	static StringBuilder answer;
	static int[][] arr = new int[11][11];
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	static int n;
	static int dir = 0;
	
	public static boolean isInRange(int x,int y) {
		return x>0 && y>0 && x<=n && y<=n;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int tc=1; tc<=t; tc++) {
			answer = new StringBuilder();
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			
			int count = 2;
			int nx,ny;
			nx = ny = 1;
			arr[1][1] = 1;
			dir = 0;
			int size = n*n;
			
			while(count<=(size)) {
				if(!isInRange(nx+dx[dir], ny+dy[dir]) || arr[nx+dx[dir]][ny+dy[dir]]!=0) {
					++dir;
					dir = dir % dx.length;
				} else {
					nx += dx[dir];
					ny += dy[dir];
					arr[nx][ny] = count;
					++count;
				}
			}
			
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					answer.append(arr[i][j] + " ");
				}
				answer.append("\n");
			}
			System.out.println("#" + tc);
			System.out.print(answer);
			
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					arr[i][j] = 0;
				}
			}
		}
	}
}
