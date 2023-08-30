import java.util.*;
import java.io.*;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static long[][] dp = new long[31][31];
	
	static void solution() {
		for(int i=1; i<31; i++) {
			dp[1][i] = i;
		}
		for(int i=2; i<31; i++) {
			dp[i][i] = 1;
			for(int j=i+1; j<31; j++) {
				for(int k=1; k<j; k++) {
					dp[i][j] += dp[i-1][k];
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		int t = Integer.parseInt(br.readLine());
		solution();
		int n,m;
		while(--t>=0) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			System.out.println(dp[n][m]);
		}
	}
}
