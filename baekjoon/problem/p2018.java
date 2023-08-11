
import java.io.*;
import java.util.*;

public class p2018{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

		public static int sqrt(long value) {
			long l = 0;
			long r = value;

			while(l + 1 < r) {
				long  mid = (l + r) >> 1;	

				if(mid * mid <= value) {
					l = mid;	
				} else {
					r = mid;	
				}
			}

			return (int)l;
		}

    public static void solve() throws IOException {
			int n = Integer.parseInt(br.readLine());

			int sqrtN = sqrt((long)n * 2);

			int cnt = 0;

			for(int i = 1; i <= sqrtN; i++) {
				if(n * 2 % i == 0) {
					int k = i;
					int kk = n * 2 / k;
					if((kk - k + 1) % 2 == 0) {
						cnt++;	
					}
				}	
			}

			sb.append(cnt).append("\n");
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

