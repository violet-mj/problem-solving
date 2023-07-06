import java.io.*;
import java.util.*;

public class p15897 {
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

    public static void solve() throws IOException {
			int n = Integer.parseInt(br.readLine());
			if (n == 1) {
				sb.append(1).append("\n")	;
				return;
			}
			int sqrtN = (int) Math.sqrt(n - 1);
			int check = (int) (n - 1) / sqrtN;
			long result = 0;


			for(int i = 1; i <= check; i++) {
				result += (long) (n - 1) / i	;
			}	

			while(sqrtN > 1) {
				int l = (int) (n - 1) / sqrtN;
				l++;
				int r = (int) (n - 1) / (sqrtN - 1);
				result += (sqrtN - 1) * (r - l + 1);
				sqrtN--;
			}

			result += n;

			sb.append(result).append("\n");

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

