import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *       트리 구성 원소가 무엇인지 판단
 * 2. strategy: 풀이전략
 *     완전 이진트리임을 이용하여 인덱스로 계산
 * 3. note: 주의할 사항(특이사항)
 */

public class Main {
	
	static String[] tree = new String[201];
	static int n;
	
	public static boolean checkValid() {
		int leftChild;
		boolean isOperator = true;
		boolean isLeaf = true;
		String now;
		boolean isValid = true;
		for(int i=1; i<=n; i++) {
			leftChild = i*2;
			now = tree[i];
			isOperator = now.charAt(0)=='+' || now.charAt(0)=='*' || now.charAt(0)=='-' || now.charAt(0)=='/';
			isLeaf = leftChild>n;
			isValid = (!isOperator && isLeaf) || (isOperator &&!isLeaf);
			if(!isValid) {
				break;
			}
		}
		return isValid;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for(int tc=1; tc<=10; tc++) {
			n = Integer.parseInt(br.readLine());
			for(int i=1; i<=n; i++) {
				st = new StringTokenizer(br.readLine());
				tree[Integer.parseInt(st.nextToken())] = st.nextToken();
			}
			
			sb.append("#"+tc+" "+(checkValid() ? 1 : 0)+"\n");
		}
		System.out.print(sb);
	}
}
