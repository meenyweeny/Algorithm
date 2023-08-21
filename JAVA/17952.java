import java.io.*;
import java.util.*;

public class Main {

	static class Pair { // 작업을 하는 데 걸리는 분과, 끝냈을 떄 점수를 저장할 내부 클래스
		int minute, score;
		Pair(int minute, int score) {
			this.minute = minute;
			this.score = score;
		}
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n,answer;
	static ArrayDeque<Pair> ad = new ArrayDeque<>(); //작업들의 리스트를 가지고 있을 arraydeque
	
	public static void doTask() { //1~n까지 매 분 작업을 할 건데 그 때 사용할 함수
		if(ad.isEmpty()) { //작업리스트가 비어있다면 그냥 끝낸다
			return;
		}
		Pair front = ad.pollFirst(); //맨 앞에서 작업을 꺼내온다
		--front.minute; //1분 줄인다
		if(front.minute==0) { //만약 남은 분이 0이라면 그 작업이 끝난 것
			answer += front.score; //그러면 answer에 score을 더해주고 끝낸다 (그 작업 자체는 리스트에서 빠진 거)
		} else {
			ad.addFirst(front); //0이 아니라면 또 다시 작업을 해야하니까 다시 작업의 맨 앞으로 넣어준다 (순서가 작업의 우선순위)
		}
	}
	
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		
		int command,score,minute;
		for(int i=1; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			command = Integer.parseInt(st.nextToken());
			if(command==1) { //1이라면 새로운 작업이 들어온 것
				score = Integer.parseInt(st.nextToken());
				minute = Integer.parseInt(st.nextToken());
				ad.addFirst(new Pair(minute, score)); //리스트에 입력받은 작업을 넣어준다
			}
			doTask(); //작업이 들어왔든 안들어왔든 매 분 일은 해준다
		}
		System.out.println(answer); //1~n분 간의 작업이 끝난 후 answer를 출력한다
	}

}
