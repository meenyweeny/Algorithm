import java.util.*;

class Solution {
	
	static int[] cntx = new int[10];
	static int[] cnty = new int[10];
    
    public String solution(String x, String y) {
		StringBuilder answer = new StringBuilder();
		
		int count;
		for(int i=0; i<x.length(); i++) {
			++cntx[x.charAt(i)-'0'];
		}
		for(int i=0; i<y.length(); i++) {
			++cnty[y.charAt(i)-'0'];
		}
		for(int i=9; i>0; i--) {
			count = Math.min(cntx[i],cnty[i]);
			for(int j=0; j<count; j++) {
				answer.append(i);
			}
		}
		count = Math.min(cntx[0],cnty[0]);
		if(answer.length() == 0 && count>0) {
			answer.append(0);
		} else {
			for(int j=0; j<count; j++) {
				answer.append(0);
			}
		}
		
		if(answer.length() == 0) {
			answer.append(-1);
		}
        return answer.toString();
    }
}
