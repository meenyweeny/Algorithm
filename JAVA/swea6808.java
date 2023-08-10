import java.io.*;
import java.util.*;

public class Solution {

	static int[] a = new int[9];
	static int[] b = new int[9];
	static boolean[] check = new boolean[18];
	static int win,lose;
	
	public static void init() {
		for(int i=0; i<18; i++) {
			check[i] = false;
		}
		win = lose = 0;
	}
	
	public static void makeCardpack() {
		int count = 0;
		for(int i=0; i<18; i++) {
			if(!check[i]) {
				b[count++] = i+1;
			}
		}
	}
	
	private static boolean np(int[] p) {
		int n = p.length;
		int i = n-1;
		while(i>0 && p[i-1]>=p[i]) {
			--i;
		}
		if(i==0) {
			return false;
		}
		int j = n-1;
		while(p[i-1]>=p[j]) {
			--j;
		}
		swap(p,i-1,j);
		int k = n-1;
		while(i<k) {
			swap(p,i++,k--);
		}
		return true;
	}

	private static void swap(int[] p, int x, int y) {
		int temp = p[x];
		p[x] = p[y];
		p[y] = temp;
	}
	
	public static void run() {
		Arrays.sort(b);
		
		do {
			int aScore, bScore;
			aScore = bScore = 0;
			for(int i=0; i<9; i++) {
				if(a[i]<b[i]) {
					bScore += a[i];
					bScore += b[i];
				} else {
					aScore += a[i];
					aScore += b[i];
				}
			}
			if(aScore<bScore) {
				++lose;
			} else if(aScore>bScore) {
				++win;
			}
		} while(np(b));
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; tc++) {
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<9; i++) {
				a[i] = Integer.parseInt(st.nextToken());
				check[a[i]-1] = true;
			}
			makeCardpack();
			run();
			sb.append("#"+tc+" "+win+" "+lose+"\n");
			init();
		}
		
		System.out.println(sb);
	}
}
