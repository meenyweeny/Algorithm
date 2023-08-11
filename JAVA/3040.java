import java.io.*;
import java.util.*;

public class Main {
	
	static int[] small = new int[9];
	static int[] answer = new int[7];
	static void find(int count, int sum, int start) {
		if(count==7) {
			if(sum==100) {
				for (int i : answer) {
					System.out.println(i);
				}
			}
			return;
		}
		for(int i=start; i<9; i++) {
			answer[count] = small[i];
			find(count+1,sum+small[i],i+1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		for(int i=0; i<9; i++) {
			small[i] = Integer.parseInt(br.readLine());
		}
		find(0,0,0);
	}
}
