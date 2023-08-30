import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int[][] dp = new int[15][15];
		
		for(int i=1; i<15; i++) {
			dp[0][i] = i;
		}
		
		for(int i=1; i<15; i++) {
			dp[i][1] = 1;
			for(int j=2; j<15; j++) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		
		int n,k;
		for(int i=0; i<t; i++) {
			n = sc.nextInt();
			k = sc.nextInt();
			System.out.println(dp[n][k]);
		}
	}
}
