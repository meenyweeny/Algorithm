import java.io.*;
import java.util.*;

public class Main {

    static int k;
    static int[] arr;
    static int[] lotto = new int[6];
    static StringBuilder sb = new StringBuilder();

    public static void peek(int count,int start) {
        if(count==6) {
            for (int l:lotto) {
                sb.append(l + " ");
            }
            sb.append("\n");
            return;
        }

        for(int i=start; i<k; i++) {
            lotto[count] = arr[i];
            peek(count+1,i+1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());
        while(k!=0) {
            arr = new int[k];
            for(int i=0; i<k; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            peek(0,0);
            st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());
            sb.append("\n");
        }
        System.out.println(sb);
    }
}
