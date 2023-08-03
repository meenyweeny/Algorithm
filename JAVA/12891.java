import java.io.*;
import java.util.*;

public class Main {

	static int s,p;
	static int answer;
	static int a,g,c,t;
	static int[] count = new int[4];
	static int[] check = new int[4];
	static String password;
	
	public static boolean isValidPassword() {
		for(int i=0; i<4; i++) {
			if(count[i] < check[i]) {
				return false;
			}
		}
		return true;
	}
	
	public static void checkAlphabet(char ch, int value) {
		if(ch=='A') {
			count[0] += value;
		} else if(ch=='C') {
			count[1] += value;
		} else if(ch=='G') {
			count[2] += value;
		} else {
			count[3] += value;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		p = Integer.parseInt(st.nextToken());
		password = br.readLine();
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<4; i++) {
			check[i] = Integer.parseInt(st.nextToken());
		}
		
		int start = 0;
		int end = p-1;
		for(int i=start; i<=end; i++) {
			checkAlphabet(password.charAt(i),1);
		}
		answer += isValidPassword() ? 1 : 0;
		while(end<s-1) {
			++start;
			++end;
			checkAlphabet(password.charAt(start-1), -1);
			checkAlphabet(password.charAt(end), 1);
			answer += isValidPassword() ? 1 : 0;
		}
		System.out.println(answer);
	}
}
