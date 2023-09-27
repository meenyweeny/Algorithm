import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SW1263_이경민 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static final int inf = (int)1e9;
	static int n;
	static int[][] map;
	
	public static void input() throws Exception {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		map = new int[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(i!=j && map[i][j]==0) {
					map[i][j] = inf;
				}
			}
		}
	}
	
	public static void solution() {
		for(int k=0; k<n; k++) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(i==j) {
						continue;
					}
					map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; tc++) {
			input();
			solution();
			int answer = inf;
			for(int i=0; i<n; i++) {
				int comp = 0;
				for(int j=0; j<n; j++) {
					comp += map[i][j];
				}
				answer = Math.min(answer, comp);
			}
			System.out.println("#"+tc+" "+answer);
		}
	}

}
