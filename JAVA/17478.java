import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int n;
	static String[] sentence = {"\"재귀함수가 뭔가요?\"",
			"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
			"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
			"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""};
	static String[] last = {sentence[0],
			"\"재귀함수는 자기 자신을 호출하는 함수라네\""};
	
	public static void run(int step) {
		if(step>n) {
			return;
		}
		if(step==n) {
			for(int i=0; i<last.length; i++) {
				for(int j=0; j<step; j++) {
					System.out.print("____");
				}
				System.out.println(last[i]);
			}
		} else {
			for(int i=0; i<sentence.length; i++) {
				for(int j=0; j<step; j++) {
					System.out.print("____");
				}
				System.out.println(sentence[i]);
			}
		}
		run(step+1);
		for(int j=0; j<step; j++) {
			System.out.print("____");
		}
		System.out.println("라고 답변하였지.");
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		System.out.println("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
		run(0);
	}
}
