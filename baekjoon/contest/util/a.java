import java.io.*;
import java.util.*;

public class a{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

    public static void solve() throws IOException {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());

			int[] levels = new int[n];

			for(int i = 0; i < n; i++) {
				levels[i] = Integer.parseInt(st.nextToken());
			}

			for(int i = 0; i < n; i++) {
				int currLevel = levels[i];
				int res;	
				if(currLevel >= 300) {
					res = 1;
				} else if (currLevel >= 275) {
					res = 2;	
				} else if (currLevel >= 250) {
					res = 3;	
				} else {
					res = 4;	
				}

				sb.append(res).append(" ");
			}

    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        solve();
        result = sb.toString();

        br.close();
        bw.write(result);
        bw.flush();
        bw.close();
    }
}

