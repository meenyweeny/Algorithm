import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *       괄호 짝짓기
 * 2. strategy: 풀이전략
 *     조건에 맞춰 스택에 넣거나 빼기
 * 3. note: 주의할 사항(특이사항)
 */

public class Main {

	static Queue<Integer> q = new ArrayDeque<Integer>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=n; i++) {
			q.add(i);
		}
		
		while(q.size()>1) {
			q.poll();
			q.add(q.peek());
			q.poll();
		}
		
		System.out.println(q.peek());
	}
}
