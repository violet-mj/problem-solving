import java.io.*;
import java.util.*;

public class p17425{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

    public static void solve() throws IOException {
			int n = Integer.parseInt(br.readLine());
			
			long cnt = 0;
			long j = 0;

			for(long i = 1; i <= n; i = j + 1) {
				j = n / (n / i);	
				cnt +=  (n / i) * (j * ( j + 1) / 2  - i * ( i - 1) / 2) ;
			}

			sb.append(cnt).append("\n");
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
				int t = Integer.parseInt(br.readLine());
				for(int i = 0; i < t; i++) solve();
        result = sb.toString();
        br.close();
        bw.write(result);
        bw.flush();
        bw.close();
    }
}

