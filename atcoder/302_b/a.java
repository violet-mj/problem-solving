
import java.io.*;
import java.util.*;

public class a{
    public static StringBuilder sb;
    public static BufferedReader br;
    public static String result;

    public static void solve() throws IOException {
			StringTokenizer st = new StringTokenizer(br.readLine());
			long a = Long.parseLong(st.nextToken());
			long b = Long.parseLong(st.nextToken());

			long k =  a / b;

			if (a % b == 0) {
				sb.append(k).append("\n");
			} else {
				sb.append(k + 1).append("\n");
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

