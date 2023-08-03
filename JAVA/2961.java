import java.io.*;
import java.util.*;

public class Main {

	static int n,s,b;
	static int[][] food = new int[10][2];
	static int answer = (int)2e9;
	
	public static void subset(int now, int count, int start, int sour, int bit) {
		if(now==count) {
			answer = Math.min(answer, Math.abs(sour-bit));
			return;
		}
		for(int i=start; i<n; i++) {
			subset(now+1,count,i+1,sour*food[i][0],bit+food[i][1]);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			food[i][0] = Integer.parseInt(st.nextToken());
			food[i][1] = Integer.parseInt(st.nextToken());
		}
		for(int i=1; i<=n; i++) {
			subset(0,i,0,1,0);
		}
		System.out.println(answer);
	}
}
