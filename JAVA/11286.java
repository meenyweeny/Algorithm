import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *     절댓값이 가장 작은 값 확인
 * 2. strategy: 풀이전략
 *     음수, 양수를 서로 다른 PriorityQueue에 관리
 * 3. note: 주의할 사항(특이사항)
 */

public class Main {
	
	static int n;
	static PriorityQueue<Integer> neg = new PriorityQueue<Integer>(Comparator.reverseOrder());
	static PriorityQueue<Integer> pos = new PriorityQueue<Integer>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		int k;
		while(--n>=0) {
			k = Integer.parseInt(br.readLine());
			if(k==0) {
				if(neg.isEmpty() && pos.isEmpty()) {
					sb.append(0 + "\n");
				} else if(neg.isEmpty()) {
					sb.append(pos.poll() + "\n");
				} else if(pos.isEmpty()) {
					sb.append(neg.poll() + "\n");
				} else if(Math.abs(neg.peek()) <= Math.abs(pos.peek())) {
					sb.append(neg.poll() + "\n");
				} else {
					sb.append(pos.poll() + "\n");
				}
			} else {
				if(k<0) {
					neg.add(k);
				} else {
					pos.add(k);
				}
			}
		}
		System.out.print(sb);
	}
}
