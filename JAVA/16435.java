import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *     기준값이 변할 때, 기준을 만족하는 수의 개수 찾기
 * 2. strategy: 풀이전략
 *     ascending order로 정렬한 후 순차 탐색
 * 3. note: 주의할 사항(특이사항)
 */

public class Main {
	
	static final int size = (int)1e3;
	static int n,l;
	static int[] h;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int l = Integer.parseInt(st.nextToken());
		h = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			h[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(h);
		for(int k:h) {
			if(k<=l) {
				++l;
			} else {
				break;
			}
		}
		
		System.out.println(l);
	}
}
