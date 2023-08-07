import java.io.*;
import java.util.*;

/*
 * 1. summary: 문제 해석
 *       나의 앞에 있는 것들 중 나보다 높은 높이의 탑이 몇 번째 인덱스에서 가장 처음 나올까
 * 2. strategy: 풀이전략
 *     조건에 맞춰 스택에 넣거나 빼기
 * 3. note: 주의할 사항(특이사항)
 */
class Point {
	int value;
	int index;
	
	public Point(int v,int i) {
		value = v;
		index = i;
	}
}

public class Main {
	
	static final int maxSize = (int)5e5 + 1;
	static Stack<Point> top = new Stack<Point>();
	static int[] answer = new int[maxSize];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		int tmp;
		top.push(new Point((int)2e9,0));
		for(int i=0; i<n; i++) {
			tmp = Integer.parseInt(st.nextToken());
			if(top.empty()) {
				top.push(new Point(tmp,i+1));
				continue;
			}
			if(top.peek().value > tmp) {
				answer[i+1] = top.peek().index;
				top.push(new Point(tmp,i+1));
				continue;
			} else {
				while(top.size()>1) {
					if(top.peek().value<tmp) {
						answer[top.pop().index] = top.peek().index;
					} else {
						break;
					}
				}
				top.push(new Point(tmp,i+1));
			}
		}
		while(top.size()>1
				) {
			answer[top.pop().index] = top.peek().index;
		}
		for(int i=1; i<=n; i++) {
			sb.append(answer[i] + " ");
		}
		System.out.print(sb);
	}
}
