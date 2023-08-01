import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Solution {

	static ArrayList<Integer> list = new ArrayList<Integer>();
	static int dump;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int tc=1; tc<=10; tc++) {
			list.clear();
			dump = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for(int i=0; i<100; i++) {
				list.add(Integer.parseInt(st.nextToken()));
			}
			boolean flag = false;
			while(dump>0) {
				list.sort(Comparator.reverseOrder());
				if(list.get(0)==list.get(99)) {
					flag = true;
					break;
				}
				--dump;
				list.set(0, list.get(0)-1);
				list.set(99, list.get(99)+1);
			}
			list.sort(Comparator.reverseOrder());
			if(!flag) {
				System.out.println("#"+tc+" "+(list.get(0)-list.get(99)));
			} else {
				System.out.println("#"+tc+" "+list.get(0));
			}
		}
	}
}
