import java.awt.*;
import java.io.*;
import java.util.*;

public class JUN2239_이경민 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static class Pair<A,B> {
        A x;
        B y;
        Pair(A x,B y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[][] map = new int[9][9];
    static ArrayList<Pair<Integer,Integer>> puzzles = new ArrayList<>();
    static boolean flag;

    public static void input() throws Exception {
        for(int i=0; i<9; i++) {
            String str = br.readLine();
            for(int j=0; j<9; j++) {
                map[i][j] = str.charAt(j) - '0';
                if(map[i][j]==0) {
                    puzzles.add(new Pair(i,j));
                }
            }
        }
    }

    public static void print() {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sb.append(map[i][j]);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    public static boolean isValid(int x,int y,int value) {
        for(int i=0; i<9; i++) {
            if(map[i][y]==value) {
                return false;
            }
            if(map[x][i]==value) {
                return false;
            }
        }
        x/=3; x*=3;
        y/=3; y*=3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(map[x+i][y+j]==value) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void process(int index) {
        if(flag) {
            return;
        }
        if(index==puzzles.size()) {
            print();
            flag = true;
            return;
        }
        Pair<Integer, Integer> p = puzzles.get(index);
        for(int i=1; i<10; i++) {
            if(isValid(p.x,p.y,i)) {
                map[p.x][p.y] = i;
                process(index+1);
                map[p.x][p.y] = 0;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        input();
        process(0);
    }
}
