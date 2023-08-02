import java.io.*;
import java.util.*;

public class Main {

	static StringBuilder answer = new StringBuilder();
	static int[][] arr = new int[1025][1025];
	static int n,m;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1; j<=n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
			}
		}
		
		int x,xx,y,yy;
		for(int i=1; i<=m; i++) {
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			xx = Integer.parseInt(st.nextToken());
			yy = Integer.parseInt(st.nextToken());
			answer.append((arr[xx][yy]+arr[x-1][y-1]-arr[xx][y-1]-arr[x-1][yy]));
			answer.append("\n");
		}
		
		System.out.println(answer);
	}
}
