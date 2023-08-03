import java.io.*;
import java.util.*;

public class Solution {

	static int n,m;
	static int answer = -1;
	static int[][] map = new int[15][15];
	
	public static void getFlyCount() {
		int start = 0;
		int end = 0;
		while(end+m<=n) {
			start = 0;
			while(start+m<=n) {
				int sum = 0;
				for(int i=0; i<m; i++) {
					for(int j=0; j<m; j++) {
						sum += map[i+start][j+end];
					}
				}
				++start;
				answer = Math.max(answer, sum);
			}
			++end;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		StringBuilder sb = new StringBuilder();
		
		for(int tc=1; tc<=t; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			answer = -1;
			
			for(int i=0; i<n; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			getFlyCount();
			
			sb.append("#"+tc+" "+answer+"\n");
		}
		System.out.println(sb);
	}
}
