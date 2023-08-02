import java.io.*;
import java.util.*;

public class Main {

	static StringBuilder answer = new StringBuilder();
	static int[] arr = new int[100001];
	static int n,m;
	static int i,j;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int k=1; k<=n; k++) {
			arr[k] = arr[k-1] + Integer.parseInt(st.nextToken());
		}
		
		for(int k=1; k<=m; k++) {
			st = new StringTokenizer(br.readLine());
			i = Integer.parseInt(st.nextToken());
			j = Integer.parseInt(st.nextToken());
			answer.append(arr[j]-arr[i-1]);
			answer.append("\n");
		}
		System.out.println(answer);
	}
}
