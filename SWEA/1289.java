import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t;
		t = Integer.parseInt(br.readLine());
		int answer = 0;
		for(int tc=1; tc<=t; tc++) {
			String now = br.readLine();
			answer = 0;
			char[] ch = now.toCharArray();
			char c = ch[0] == '1' ? 'a' : ch[0];
			for(int i=0; i<ch.length; i++) {
				if(ch[i]!=c) {
					++answer;
					c = ch[i];
				}
			}
			System.out.println("#" + tc + " " + answer);
		}
	}

}
