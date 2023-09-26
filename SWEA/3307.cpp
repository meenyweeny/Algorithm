import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class SW3307_이경민 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[] arr,dp;
	static ArrayList<Integer> lis = new ArrayList<>();
	static int n,answer;
	
	public static void input() throws Exception {
		n = Integer.parseInt(br.readLine());
		arr = new int[n];
		dp = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
	}
	
	public static void solve() {
		dp[0] = 1;
		for(int i=1; i<n; i++) {
			for(int j=0; j<i; j++) {
				dp[i] = Math.max(dp[i], (arr[i] > arr[j] ? dp[j] : 0));
			}
			++dp[i];
		}
		for(int i=0; i<n; i++) {
			answer = Math.max(answer, dp[i]);
		}
	}
	
	public static void main(String[] args) throws Exception {
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; tc++) {
			answer = 0;
			input();
			solve();
			System.out.println("#"+tc+" "+answer);
		}
	}
}
