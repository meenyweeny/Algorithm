import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *       주어진 수들 중 두 개를 골라서 m을 넘지 않는 것들 중 가장 가까운 것은?
 * 2. strategy: 풀이전략
 *     두 가지 수를 골라서 m에 가장 가까운 거 찾기
 * 3. note: 주의할 사항(특이사항)
 */

public class Main {
	
	static int n,m;
	static ArrayList<Integer> list = new ArrayList<Integer>();
	
	public static int getSnackWeight() {
		Collections.sort(list,Collections.reverseOrder());
		int front,back,now,length,answer;
		length = list.size();
		front = 0;
		answer = -1;
		while(front<length-1) {
			back = front + 1;
			while(back<length) {
				now = list.get(front) + list.get(back);
				if(now<=m) {
					answer = Math.max(answer, now);
				}
				++back;
			}
			++front;
		}
		return answer;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int t = Integer.parseInt(br.readLine());
		int k;
		for(int tc=1; tc<=t; tc++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			
			list.clear();
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<n; i++) {
				k = Integer.parseInt(st.nextToken());
				if(k<=m) {
					list.add(k);
				}
			}
			sb.append("#"+tc+" "+getSnackWeight()+"\n");
		}
		System.out.print(sb);
	}
}
