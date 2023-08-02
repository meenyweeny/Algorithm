import java.io.*;
import java.util.*;

public class Main {
    
	static StringBuilder answer = new StringBuilder();
	static int[] arr = new int[9];
	static int r;
	static int n;
	static boolean visited[] = new boolean[9];
	
	public static void s(int start, int cnt) {
		if(cnt==r) {
			for(int i=0; i<r; i++) {
				answer.append(arr[i]);
				answer.append(' ');
			}
			answer.append('\n');
			return;
		}
		for(int i=start; i<=n; i++) {
			if(visited[i]) {
				continue;
			}
			arr[cnt] = i;
			visited[i] = true;
			s(i+1,cnt+1);
			visited[i] = false;
		}
	}
    
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		
		s(1,0);
		System.out.println(answer);
	}
}
