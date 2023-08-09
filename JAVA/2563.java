import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	static boolean board[][] = new boolean[100][100];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		while(--n>=0) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			--x; --y;
			for(int i=0; i<10; i++) {
				for(int j=0; j<10; j++) {
					board[x+i][y+j] = true;
				}
			}
		}
		
		int answer = 0;
		for(int i=0; i<100; i++) {
			for(int j=0; j<100; j++) {
				answer += board[i][j] ? 1 : 0;
			}
		}
		
		System.out.println(answer);
	}
}
