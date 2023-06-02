import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int map[][] = new int[5][5];
    static boolean check[][] = new boolean[5][5];

    static int bingo() {
        int count = 0;
        boolean flag = true;
        for(int i=0; i<5; i++) {
            flag = true;
            for(int j=0; j<5; j++) {
                flag = flag && check[i][j];
            }
            if(flag) ++count;
        }
        for(int i=0; i<5; i++) {
            flag = true;
            for(int j=0; j<5; j++) {
                flag = flag && check[j][i];
            }
            if(flag) ++count;
        }
        flag = true;
        for(int i=0; i<5; i++) {
            flag = check[i][i] && flag;
        }
        if(flag) ++count;
        flag = true;
        for(int i=0; i<5; i++) {
            flag = check[i][4-i] && flag;
        }
        if(flag) ++count;
        return count;
    }

    static void check(int num) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(map[i][j]==num) {
                    check[i][j] = true;
                    return;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        for(int i=0; i<5; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<5; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int command;
        int count = 0;
        for(int i=0; i<5; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<5; j++) {
                ++count;
                command = Integer.parseInt(st.nextToken());
                check(command);
                if(bingo()>2) {
                    sb.append(count);
                    bw.write(sb.toString());
                    bw.flush();
                    bw.close();
                    return;
                }
            }
        }
    }
}
