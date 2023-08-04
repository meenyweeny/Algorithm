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

	static String str;
	static int length;
	
	public static boolean isValidString() {
		Stack<Character> st = new Stack<Character>();
		char ch;
		for(int i=0; i<length; i++) {
			ch = str.charAt(i);
			if(ch=='('||ch=='{'||ch=='['||ch=='<') {
				st.push(ch);
			} else {
				if(st.empty()) {
					return false;
				}
				if(ch==')') {
					if(st.peek()!='(') {
						return false;
					} else {
						st.pop();
					}
				} else if(ch==']') {
					if(st.peek()!='[') {
						return false;
					} else {
						st.pop();
					}
					
				} else if(ch=='>') {
					if(st.peek()!='<') {
						return false;
					} else {
						st.pop();
					}
					
				} else if(ch=='}') {
					if(st.peek()!='{') {
						return false;
					} else {
						st.pop();
					}
					
				}
			}
		}
		return st.empty();
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for(int tc=1; tc<=10; tc++) {
			length = Integer.parseInt(br.readLine());
			str = br.readLine();
		
			sb.append("#"+tc+" "+(isValidString() ? 1 : 0)+"\n");
		}
		System.out.println(sb);
	}
}
