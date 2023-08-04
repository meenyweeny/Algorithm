import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 * 앞에서 뺀 수 처리 후 뒤에 넣기
 * 2. strategy: 풀이전략
 * 큐
 * 3. note: 주의할 사항(특이사항)
 */

public class Main {

	static StringBuilder sb = new StringBuilder();
	static Queue<Integer> dq = new ArrayDeque<Integer>();
	
	public static void getPassword() {
		while(true) {
			for(int i=1; i<=5; i++) {
				int now = dq.poll();
				now -= i;
				if(now<=0) {
					return;
				}
				dq.add(now);
			}	
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int tc=1; tc<=10; tc++) {
			br.readLine();
			st = new StringTokenizer(br.readLine());
			
			dq.clear();
			
			for(int i=0; i<8; i++) {
				dq.add(Integer.parseInt(st.nextToken()));
			}
			
			getPassword();
			
			sb.append("#"+tc+" ");
			for(int d:dq) {
				sb.append(d + " ");
			}
			sb.append(0);
			sb.append("\n");
		}
		
		System.out.println(sb);
	}
}
