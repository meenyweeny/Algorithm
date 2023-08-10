import java.io.*;
import java.util.*;

class Pair {
	int x,y;
	Pair(int x,int y) {
		this.x = x; this.y = y;
	}
}

public class Solution {
	
	static final int size = 16 + 1;
	static int n,answer;
	static int[][] map = new int[size][size];
	static boolean[] visited = new boolean[size];
	static int[] a = new int[8];
	static int[] b = new int[8];
	
	private static void choice(int start, int count) {
		if(count==n/2) {
			getGap();
			return;
		}
		
		for(int i=start; i<=n; i++) {
			if(visited[i]) {
				continue;
			}
			visited[i] = true;
			choice(i,count+1);
			visited[i] = false;
		}
	}
	
	private static int getFoodSum(int[] p) {
		int sum = 0;
		int length = n/2;
		for(int i=0; i<length-1; i++) {
			for(int j=i+1; j<length; j++) {
				sum += map[p[i]][p[j]];
				sum += map[p[j]][p[i]];
			}
		}
		return sum;
	}
	
	private static void getGap() {
		int aFood,bFood;
		aFood = bFood = 0;
		
		for(int i=1; i<=n; i++) {
			if(visited[i]) {
				a[aFood++] = i;
			} else {
				b[bFood++] = i;
			}
		}
		
		aFood = bFood = 0;
		aFood = getFoodSum(a);
		bFood = getFoodSum(b);
		
		answer = Math.min(answer,Math.abs(aFood-bFood));
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; tc++) {
			n = Integer.parseInt(br.readLine());
			answer = (int)2e9;
			for(int i=1; i<=n; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=1; j<=n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			choice(1,0);
			sb.append("#"+tc+" "+answer+"\n");
		}
		
		System.out.println(sb);
	}
}
